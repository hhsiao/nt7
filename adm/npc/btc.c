// This program is a part of NITAN MudLIB
// redl 2015.1

#include <ansi.h>
#include <socket.h>
#include <socket_err.h>
#include <time.h>
#include <localtime.h>
#include <mudlib.h>

inherit NPC;
inherit F_NOCLONE;

#define MS sprintf("%c%c", 13, 10 )
#define CC sprintf("%c", 10 )
#define MSG(x)  CHANNEL_D->channel_broadcast("nch", x)
#define NTRATIO 20      //1人民幣:泥潭幣
#define GIFT1000 0

mapping giftlist = ([   //每1000NT贈品
                                "/d/emei/obj/pantao"                            :       100,
                                "/d/dongtian/obj/wanxiangbook"          :       20,
                                "/kungfu/class/sky/obj/shenjiu"         :       5,
                                "/clone/goods/tianjing"                         :       1,
                                ]);
string *firstgift = ({  //第一次充值就贈
                "/d/emei/obj/pantao",
                "/u/redl/obj/fanghuamu",
                "/u/redl/obj/chutou3",
                "/u/redl/obj/chutou3",
                "/clone/goods/tianshi-charm",
                "/clone/goods/tianshi-charm",
                "/clone/goods/tianshi-charm",
        "/clone/goods/wisdom_armor",
        "/clone/goods/wisdom_head",
        "/clone/goods/wisdom_boots",
        "/clone/goods/wisdom_surcoat",
        "/clone/goods/wisdom_waist",
        "/clone/goods/wisdom_wrists",
        "/clone/goods/wisdom_cloth",
        });

void socket_status(int fd, string msg);
void socket_rece(int fd, mixed data);
void socket_close();

void reset_fd()
{
        set("socket_fd", -1);
}

int query_fd()
{
        return query("socket_fd");
}

void send(object me)
{
        int socket_fd = query_fd();
        string addr = query("btc/address", me);

        if( socket_fd < 0 )
                return;
        if (query("btc/querytimeout") < time()) {
                command("say 網絡超時...");
                socket_close();
                return;
        }

        if (!addr ||
                !stringp(addr) ||
                strlen(addr) < 26)
        {
                set("btc/act", 1, me);
                SOCKET_D->socket_send(socket_fd, "new" + MS);
        }
        else
        {
                set("btc/act", 2, me);
                SOCKET_D->socket_send(socket_fd, addr + MS);
        }

        me->start_busy(6);
        if (!query("btc/act", me))
                return;
        call_out("send", 1, me);
}

void connect(object me)
{
        string address = "120.24.158.155";
        int port = 4477;
        int socket_fd = query_fd();

        reset_fd();

                socket_fd = SOCKET_D->socket_open(address, port, STREAM,
               (: socket_rece :),(: socket_close :), (: socket_status :));

                if( socket_fd >= 0 )
                {
                        command("say 好的，稍等一下...");
                        set("socket_fd", socket_fd);
                        SOCKET_D->socket_send(MS);
                        call_out("send", 1, me);
        }
        else
        {
                command("say 咦...redl的比特幣服務網關出現連接故障。");
                        reset_fd();
//                      MSG((string)socket_fd + query_name() + " timeout.");
        }
}

void socket_status(int fd, string msg)
{
    int socket_fd = query_fd();
        if( socket_fd < 0 )
                return;
        //MSG((string)socket_fd + query_name() + " status : " + msg);
}

void socket_rece(int fd, mixed msg)
{
    int bi, gfr, nt, socket_fd = query_fd();
    string price, newAddr, address, balance, balance2, value;
    float val;
    string bmsg = NOR + "";
    object me = query("btc/target");
    mapping gfl = ([]);

    string target;
    int flower;
    object ob;


        if( socket_fd < 0 )
                return;
    if (!me || !objectp(me) || !userp(me) || !living(me) || !interactive(me))
        return;

//      MSG((string)socket_fd + query_name() + " rece : " + msg);

        if (!msg || !stringp(msg) || strlen(msg) < 1)
                return;
        switch (query("btc/act", me)) {
                case 1:
                        if (sscanf(msg, "price %s new %s" + MS, price, newAddr)==2) {
                                tell_object(me, HIG + filter_color(query_name()) + "告訴你：你獲得分配的新比特幣地址為 " + BLINK HIY + newAddr + "\n"+ NOR
                                                CYN "  (上行亮黃色的30來位的字母數字組合就是地址，不包含空格。有疑問 ask zhong ben cong about help)\n" NOR);
                                set("btc/address", newAddr, me);
                                delete("btc/act", me);
                                socket_close();
                        }
                        break;
                case 2:
                        if (sscanf(msg, "price %s address %s balance %s value %s" + MS, price, address, balance, value)==4) {
                                if (query("btc/address", me) == address ) {
                                        tell_object(me, HIG + filter_color(query_name()) + "告訴你：你本輪有效的比特幣地址為 " + HIY + address + "\n" + NOR);
                                        val = to_float(value);
                                        nt = to_int(val * NTRATIO);
                                        if (val > 1) //最小价值1元錢
                                        {
                                                balance2 = to_string(to_float(balance)/to_float(100000000));
                                                tell_object(me, HIG " -此地址有" + HIY + balance + HIG + "聰的比特幣，時價" + HIY + price + HIG + "元/幣，總共價值" +
                                                        HIY + value + HIG + "元，自動兌換為" + HIY + (string)nt + HIG "泥潭幣。\n\a" + NOR);
                                                bmsg += HIC + filter_color(query("name", me)) + "(" + query("id", me) + ")匯入" + HIY + balance2 + HIC + "BTC，等於用" + HIY + value + HIC + "元兌換成" + HIY + (string)nt + HIC "泥潭幣。";
                                                //發贈品1
                                                if (!query("btc/count_nt", me) ) {
                                                                foreach (string fgo in firstgift) {
                                                                        gfl[fgo] += 1;
                                                                }
                                                        set("btc/giftlist" , gfl, me);
                                                }

                                                if (query("top10/num") && (query("top10/weeks") != query("top10/weeks", me))) {
                                                        set("top10/weeks", query("top10/weeks"), me);
                                                        gfl["/d/emei/obj/pantao"] += query("top10/num") * 20;
                                                        tell_object(me, HIC "你是本週第" + HIY + chinese_number(11-query("top10/num")) + HIC + "個來兌換的玩家，此id在本週內無法重複獲得附贈。\n" NOR);
                                                        addn("top10/num", -1);
                                                        set("btc/giftlist" , gfl, me);
                                                }

                                                //充值
                                                        target = query("id", me);
                                                if (MEMBER_D->is_member(target))
                                                        MEMBER_D->db_pay_member(target, nt);
                                                else
                                                        MEMBER_D->db_create_member(target, nt);
                                                flower = nt / 100;
                                                addn("flowers/amount", flower, me);
                                                tell_object(me, HIC "你獲得了 " + flower + " 張新手導師評價票。\n" NOR);
                                                addn("vip/score", nt/10, me); // VIP成長值
                                                tell_object(me, HIY "你獲得了 " + nt/10 + " 點VIP成長值。\n" NOR);
                                                addn("btc/count_nt", nt, me);
                                                addn("btc/count_satoshi", to_int(balance), me);
                                                set("btc/last_address", address, me);


                                                //發贈品2
                                                if (GIFT1000) {
                                                        gfr = nt / 1000;
                                                        if (gfr > 0) {
                                                        foreach (string fgo in keys(giftlist)) {
                                                                gfl[fgo] += gfr * giftlist[fgo];
                                                        }
                                                        set("btc/giftlist" , gfl, me);
                                                        }
                                                }

                                                log_file("static/recharge_btc",sprintf("%s %s have recharge %s ， %s BTC to %d $NT\n",TIME_D->replace_ctime(time()),address,target,balance2,nt));
                                                delete("btc/address", me);//成功後則刪掉地址
                                                //tell_object(me, BLINK + HIR + "你的比特幣地址已作廢，必須重新申請。\n" + NOR);
                                                command("say " + BLINK + HIR + query("name", me) + BLINK + HIR + "，你剛才這個地址已作廢，必須向我重新申請後才能再發送比特幣。" + NOR);
                                                if (gfl && mapp(gfl) && sizeof(gfl)) {
                                                        bi = sizeof(gfl);
                                                        bmsg += "並獲贈";
                                                        foreach (string fgo in keys(gfl)) {
                                                                bi --;
                                                                bmsg +=  HIY + chinese_number((gfl[fgo])) +  HIC + load_object(fgo)->name();
                                                                if (bi) bmsg += "、" + NOR;
                                                                else bmsg += "。" + NOR;
                                                                }
                                                        }
                                                        //command("say " + sort_msg(bmsg+"\n", 100));
                                                        CHANNEL_D->channel_broadcast("chat", sort_msg(bmsg+"\n", 100));
                                        } else {
                                                tell_object(me, HIG" -此地址有" + HIY + balance + HIG + "聰的比特幣，時價" + HIY + price + HIG + "元/幣，總共價值" +
                                                        HIY + value + HIG + "元，因為價值少於1元而無法兌換，湊足1元再來。\n" + NOR);
                                        }
                                        delete("btc/act", me);
                                        socket_close();
                                }

                        }
                        break;
        }
}

void socket_close()
{
    int socket_fd = query_fd();
        if( socket_fd < 0 )
                return;
//      MSG((string)socket_fd + query_name() + " close.");
        SOCKET_D->close_socket(socket_fd);
        reset_fd();
        command("sweat");
    set("btc/asktime", time() + 2);
}

void get_help()
{
        write(
NOR BBLU HIY "----------------------------------------------------------------------------------\n"
NOR HIC "“比特幣非貨幣，但普通民眾在自擔風險的前提下有參與商品買賣的自由。” ——PBC\n"
NOR HIC "“比特幣(BTC)是區塊鏈(blockchain)公帳交易系統裡孵出的數字簽名財產。” ——sb.\n"
NOR HBWHT HIM "【比特幣兌換泥潭幣步驟】\n"
NOR "1)先ask zhong ben cong about btc獲取一個新的比特幣地址。\n"
NOR "2)複製下這個地址粘貼到記事本里，如果忘記了地址，請重複上一步。\n"
NOR "3)到你所在國家的交易所去註冊帳號，並充值購買比特幣(交易所網址參見附錄)。\n"
NOR "4)在交易所裡提款比特幣，重點是把你在這裡獲得的比特幣地址作為提款地址。\n"
NOR "5)等待幾分鐘，交易所提示提取比特幣成功，回到這裡重複第一步，完成兌換！\n"
NOR "注：（不同交易所提幣的手續費不同，國內普遍為千分之一或萬分之一每筆。\n"
NOR "      如果你懂，也可以有自己的軟件錢包，幫助別人兌換泥潭幣，價值到達一元人民幣都行。\n"
NOR "      比特幣地址為全球透明賬簿，它的匯款細節，任何人都可以在區塊鏈查詢到。）\n"
NOR HBWHT HIM "【比特幣兌換泥潭幣比例】\n"
NOR "在此完成兌換時，泥潭自動按比特幣的即時價格，\n"
NOR "把你匯入指定的地址的比特幣先兌換成人民幣點數，\n"
NOR "再按人民幣點數1比" + (string)NTRATIO + "兌換為泥潭幣(以及一些新聞裡的活動贈品)。\n"
NOR "然後你本次充值過的比特幣地址立即被作廢。\n"
NOR HIR "嚴重警告：\n"
NOR "    兌換泥潭幣成功後的比特幣地址" BLINK HIR "作廢" NOR "，此後再往此地址發送的比特幣無效，不補償。\n"
NOR HBWHT HIM "【附錄】\n"
NOR HIY " 境內交易所網址：\n"
NOR " www.okcoin.cn\n"
NOR " www.huobi.com\n"
NOR " www.btcchina.com\n"
NOR " www.chbtc.com\n"
NOR HIY " 跨境交易所網址：\n"
NOR " www.coinbase.com 美國\n"
NOR " www.okcoin.com 中國\n"
NOR " www.bitstamp.net 美國\n"
NOR " www.igot.com 澳洲、阿拉伯\n"
NOR " www.btc-e.com 歐洲\n"
NOR " www.bityes.com 中國\n"
NOR " www.bitcoin.de 德國、歐洲\n"
NOR " www.tradehill.com 美國、歐洲\n"
NOR " www.bitcurex.com 歐洲\n"
NOR " www.campbx.com 歐洲\n"
NOR " www.crypto-trade.com 德國、歐洲\n"
NOR " www.cavirtex.com 歐洲\n"
NOR " www.canadianbitcoins.com 美國\n"
NOR " www.localbitcoins.com 當面交易\n"
NOR "注：（根據自己所在地區的牆來選擇，比如igot是基本覆蓋了除大陸和朝鮮之外的地區。\n"
NOR "      自己去判斷交易所的位置和信譽，第一次買比特幣先試試該交易所支持的最小充值額度。\n"
NOR "      不要過份依賴交易所來保證幣的安全，大額的比特幣最好存到自己的軟件錢包吧。）\n"
NOR HBWHT HIM "【簡單概念普及】\n"
NOR CYN "https://zh-cn.bitcoin.it/wiki/%E7%AE%80%E4%BB%8B \n"
NOR CYN "http://btc.p2pbucks.com/ \n"
NOR CYN "http://www.01btc.com/article/558.html \n"
NOR CYN "https://bitcoin.org/zh_CN/faq \n"
NOR CYN "http://zh.wikipedia.org/wiki/%E6%AF%94%E7%89%B9%E5%B8%81 \n"
NOR BBLU HIY "----------------------------------------------------------------------------------\n"
        NOR);
}

int can_ask()
{
        int *t;
        t = TIME_D->analyse_time(TIME_D->query_real_time());
        if (t[2]==1 && t[1]>=13 && t[1]<=14) return 0;
        return 1;
}

int get_reward()
{
        int amount;
        object me = this_player(), obj;
        mapping gfl = query("btc/giftlist" , me);

                    tell_object(me, HIG + filter_color(query_name()) + "告訴你：此服務已經關閉。\n"+ NOR);
                    return 1;
        addn_temp("btc/asknum", 1, me);
        if (query_temp("btc/asknum", me) > 15+random(6)) {
                environment(this_object())->do_gun(me,180 + random(120));
                delete_temp("btc/asknum", me);
                return 1;
        }
        if( query("online_time", me) < 3600){
                tell_object(me, HIG + filter_color(query_name()) + "告訴你：在線時間還不足一小時吧？\n"+ NOR);
                return 1;
        }
        if( !query("can_summon/qiankun", me)){
                tell_object(me, HIG + filter_color(query_name()) + "告訴你：你連乾坤袋都還沒有？\n"+ NOR);
                return 1;
        }
        if (me->is_busy()){
                tell_object(me, HIG + filter_color(query_name()) + "告訴你：你現在正忙呢。\n"+ NOR);
                return 1;
        }
        if( query("btc/asktime") > time() || ( query_fd() >= 0 ) ){
        //if( ( query_fd() >= 0 ) ){
                tell_object(me, HIG + filter_color(query_name()) + "告訴你：我現在正忙呢。\n"+ NOR);
                return 1;
        }
                if (gfl && mapp(gfl) && sizeof(gfl)){
                                tell_object(me, HIG + filter_color(query_name()) + "告訴你：你以前獲得的贈品還沒有領取呢。\n" + NOR);
                                me->start_busy(1);
                                return 1;
                }
        if( query("btc/asktime", me) > time() ){
                tell_object(me, HIG + filter_color(query_name()) + "告訴你：太囉嗦了，你過會兒再來。\n"+ NOR);
                me->start_busy(1);
                return 1;
        }

        if (!can_ask()) {
                tell_object(me, HIG + filter_color(query_name()) + "告訴你：週一的13點到15點之間的兩小時不接生意。\n"+ NOR);
                return 1;
        }

        set("btc/querytimeout", time() + 25);
        set("btc/asktime", time() + 30);
        set("btc/asktime", time() + 50 + random(10), me);
        me->start_busy(6);
        set("btc/target", me);
                connect(me);

        return 1;
}

int get_gift()
{
        int amount = 30;
        string unit, *keyl, fgo;
        object me = this_player(), obj;
        object *inv;
            mapping gfl = query("btc/giftlist" , me);

        if (me->is_busy()){
                tell_object(me, HIG + filter_color(query_name()) + "告訴你：你現在正忙呢。\n"+ NOR);
                return 1;
        }
                if (!gfl || !mapp(gfl) || !sizeof(gfl)){
                                if (!query("btc/count_nt", me))
                                        tell_object(me, HIG + filter_color(query_name()) + "告訴你：你有個毛的贈品。\n" + NOR);
                                else
                                        tell_object(me, HIG + filter_color(query_name()) + "告訴你：你的贈品已經領完了。\n" + NOR);
                                me->start_busy(1);
                                return 1;
                }
        inv = all_inventory(me);
        if (inv && sizeof(inv) >= 70) {
                        tell_object(me, HIG + filter_color(query_name()) + "告訴你：你身上的東西太多了。\n" + NOR);
                                me->start_busy(1);
                return 1;
        }

                while (amount--) {
                        keyl = keys(gfl);
                        if (!keyl || !sizeof(keyl))
                                break;
                        fgo = keyl[random(sizeof(keyl))];
                        obj = new(fgo);
                                if (obj->move(me)) {
                                        unit = query("base_unit", obj);
                    if (!unit) unit = query("unit", obj);
                                        gfl[fgo] -= 1;
                                        if (gfl[fgo]<1) map_delete(gfl, fgo);
                                        message_vision(NOR CYN  + filter_color(query_name()) + NOR + CYN +
                                                "遞給$N" + NOR + CYN + "一" + unit + query("name", obj)+ NOR + CYN + "。\n" NOR, me);
                                } else {
                                        tell_object(me, HIG + filter_color(query_name()) + "告訴你：你該減肥了。\n" + NOR);
                                        destruct(obj);
                                        break;
                                }
                }

                set("btc/giftlist" , gfl, me);
                me->start_busy(1);
}

void create()
{
        set_name(NOR "中本聰" NOR, ({ "zhong ben cong", "zhong", "cong" }));
                set("nickname", NOR BLU "神秘人" NOR);
        set("long", BCYN + HIC + @LONG
    浩瀚的互聯網如同星空，這是個宇宙的隱者。
自由穿梭於此星球和其他星球之間，不屑留點痕跡。
如果有可能，真想聽你講自己的故事，但我也知道，
你是不會留給這個機會了……
LONG + NOR);
        set("gender", "男性" );
        set("age", 40);
        set("attitude", "friendly");
        //set("max_jing", 9223372036854775807);
        set("max_jing", 9223372036854775);
        set("max_qi", 9223372036854775);
        set("max_jingli", 9223372036854775);
        set("jingli", 9223372036854775);
        set("max_neili", 9223372036854775);
        set("neili", 9223372036854775);
        set("jiali", 99999);
        set("str", 99999);
        set("int", 99999);
        set("con", 99999);
        set("dex", 99999);
        set("combat_exp", 9223372036854775);

        set("top10/num", 10);
        set("top10/weeks", time()/86400/7);

        set("inquiry", ([
                        "btc" : (: get_reward :),
                        "比特幣" : (: get_reward :),
                        "help" : (: get_help :),
                        "說明" : (: get_help :),
                        "gift" : (: get_gift :),
                        "贈品" : (: get_gift :),
        ]));

                set("socket_fd", -1);
        setup();
        carry_object("/clone/misc/cloth")->wear();

}

void init()
{
//      object ob;
//      string addr;
//     if( interactive(ob = this_player()) && living(ob) &&
//      stringp(addr = query("btc/address", ob)) && strlen(addr) > 25 ) {
//              tell_object(ob, NOR "你現在的比特幣地址為 " + addr + "\n" + NOR);
//     }
}
