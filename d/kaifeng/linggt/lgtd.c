// This program is a part of NITAN MudLIB 
// redl 2012/12/1 
#include <ansi.h>

#define CHANL_NAME "news"

//#define TIME_INTERVAL 86400     //闖關的間隔秒數，開放後建議=86400，一天一次，不然玩家太疲倦
#define CAN_DIE 6                       //可以持續闖關的次數，開放後建議=4，會員+1，白金+2
#define REQUIRE_LEVEL 10        //入塔的最低等級要求
#define UP_PRICE 60                             //vip塔要扣60nt手續，300天也就18000nt

inherit ROOM;

int clean_up() { return 1;}

string look_pai(object me);

int do_restart()
{
        set("lgt/entertime", time()/86400);//用途等於uid
        set("lgt/timesign", "更新於：" + ctime(time()) + "\n");
        return 1;
}

int do_stop()
{
        object me = this_player();
        if (query("lgt/stop")) {
                delete("lgt/stop");
                tell_object(me,YEL + "維修完畢，開放使用！\n" + NOR); 
        } else {
                set("lgt/stop", 1);
                tell_object(me,YEL + "開始維修，暫停使用！\n" + NOR); 
        }
        return 1;
}

void set_can_up()
{
        do_restart();
        CHANNEL_D->channel_broadcast(CHANL_NAME, 
                HIG + "開封城的上空突然風起雲湧，一座高聳入雲的"+HIY+"鐵塔"+HIG+"轟隆隆地搖晃起來，當地百姓一片譁然...\n" + NOR);
        //call_out("set_can_up", TIME_INTERVAL);
}

void create()
{
        set("short", "靈感塔底");
        set("long",
"這裡是靈感塔底，進入後頓顯另有玄機，完全不像是隻有十三層高的\n"
"樣子。少林寺別院的十三高僧堅守在此看押塔上的無數邪道高手。另有幾\n"
"個少年人聚集在旁邊的一個角落裡，大呼小叫地生著篝火，燒烤著黑狗肉\n"
"並喝酒，搞得塔內濃煙滾滾，卻全然沒有在意旁人感受。\n"
"    通往上層的樓梯邊貼著一個"+CYN+"牌子"+NOR+"。\n"
);

        set("exits", ([
//                "up"   : __DIR__"lgtxx",
                "westup"   : __DIR__"lgtxxw",
                "eastup"   : __DIR__"lgtxxe",
                "northup"   : __DIR__"lgtxxn",
                "southup"   : __DIR__"lgtxxs",
                "up"   : __DIR__"lgtxxu",
                "out"   : "/d/kaifeng/tieta", 
        ]));
        set("objects", ([ 
             __DIR__"npc/yang" : 1, 
             __DIR__"npc/ding" : 1, 
             __DIR__"npc/qi" : 1, 
             __DIR__"npc/a3" : 1, 
             __DIR__"npc/a4" : 1, 
        ])); 
        set("item_desc", ([
                "牌子": (: look_pai :),
                "pai": (: look_pai :),
                "paizi": (: look_pai :),
        ]) );
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1); 
                set("no_clean_up", 1);
                set("no_fight", "1"); 
                do_restart();//缺少這個時間會導致新人進不去。
                
        setup();
        //set_can_up();
}

void init()
{
        object me = this_player();
        if (wiz_level(me) > 5) {
                add_action("do_restart", "restart");
                add_action("do_stop", "stop");
        }
}


int total_gold()
{
        mapping ia;
        int t, i;
        string *ks;
        
        ia  =  query("lgt/owner");
        if (! mapp(ia) || ! sizeof(ia)) return 10000;
        
        t = 10000;
        
        ks = keys(ia);
        for( i=0; i<sizeof(ks); i++ )
                //write(sprintf(HIW "key：%-15s    value：%-20s\n"NOR, ks[i], ia[ks[i]]) + "\n" + NOR );
                t += to_int(ks[i]) * 10;
                
        if( t > 80000000000 ) t = 80000000000;
        return t;
}

int pay_gold(object me)
{
        mapping ia;
        int t, i, i2;
        string *ks;
        object target;
        
        ia  =  query("lgt/owner");
        if (! mapp(ia) || ! sizeof(ia)){
                addn("balance", -10000 * 10000, me);//只扣除楊小邪押金
                return 10000;
        }
        
        addn("balance", -10000 * 10000, me);//扣除楊小邪押金
        t = 10000;
        
        ks = keys(ia);
        for( i=0; i<sizeof(ks); i++ ) {
                //write(sprintf(HIW "key：%-15s    value：%-20s\n"NOR, ks[i], ia[ks[i]]) + "\n" + NOR );
                target = find_player(to_string(ia[ks[i]]));
                if (objectp(target)) {
                        if (target != me) {
                                i2 = to_int(ks[i]) * 10;
                                addn("balance", -i2 * 10000, me);//扣除
                                tell_object(target, HIG + "楊小邪偷偷告訴你道：" + query("name", me) + HIG + "挑戰失敗，照規矩向你轉賬" + chinese_number(i2) + "兩黃金！\n" + NOR);    
                                addn("balance", i2 * 10000, target);//轉入
                                t += i2;
                        }
                }
        }
                
        return t;
        
}


int valid_leave(object me, string dir)
{
        object *inv, ob;
        int amount; 
        if (dir != "out"){
                if (!playerp(me)) return -1;

                if (query("lgt/stop")) {
                        message_vision(CYN + "楊小邪攔住$N道：靈感塔正在維修 ... \n" NOR, me);
                        return -1; 
                }

                message_vision(YEL + "$N鬼鬼祟祟地張望少林眾僧和通吃幫眾人，看樣子是想溜上塔去。\n" NOR, me);
                me->start_busy(2+random(2));
                
                if( query("level", me) < REQUIRE_LEVEL) {
                        tell_object(me,CYN + "小丁急匆匆地跑過來攔住你說道：" + RANK_D->query_respect(me)  + CYN + "請三思，你等級不足"+chinese_number(REQUIRE_LEVEL)+"級，上去恐怕遭遇不測啊！\n" + NOR); 
                        message_vision(CYN + "阿三(a san)對著$N，笑得在地上打滾，滿臉“真是扯蛋，想出名也不是這樣心急的吧？”的樣子 ... \n" NOR, me);
                        return -1; 
                }
                
                // 增加vip9的特權，by Lonely
                if ( query("lgt/entertime") == query("lgt/entertime", me) && (me->query_viplevel() < 9 ||
                     query("lgt/entertime") == query("lgt/entertime2", me)) ){
                        tell_object(me,NOR"本日闖關你已經試過了，明天中午十二點後請早。\n"NOR); 
                        return -1; 
                }
        if( me->query_condition("killer") ) {
                tell_object(me, NOR"你正在被通緝，無法進入靈感塔！\n"NOR);
                return -1;
        }
        if( me->in_team() ) {
           tell_object(me, "你不能組隊進入靈感塔試煉！\n");
           return -1;
        }

            if ( objectp(query_temp("is_riding", me)) ) return notify_fail("你騎著馬沒法上靈感塔去！\n");

                if (query("balance", me) < total_gold() * 10000) {
                        tell_object(me, ( (random(2)) ? CYN"阿三擋在你前面，呲牙咧嘴地對你說道：就這麼想上去了？問過通吃小霸王沒有？？\n"NOR : CYN"阿四擋在你前面，歪瓜裂棗地對你笑道：閣下身家幾何呀？是否婚配？看和尚我如何？？\n"NOR) ); 
                        me->start_busy(3);
                        return -1; 
                }

                        if (dir == "westup") {
                ob = find_object(__DIR__"lgtxxw"); 
                if (ob) {
                inv = deep_inventory(ob);
                if( sizeof(inv) > 0 ) {
                    foreach( object ob3 in inv ) {
                                if( playerp(ob3) ) {
                                    tell_object(me,NOR"你再等等吧，現在"+query("name",ob3)+NOR+"正在"+HIC+query("short",ob)+NOR+"全力闖關中！\n"NOR); 
                                    me->start_busy(3);
                                    return -1;
                                }
                        }
                }
                }
                if (ob) destruct(ob);
                load_object(__DIR__"lgtxxw.c")->create();
                        }
                
                        if (dir == "eastup") {
                ob = find_object(__DIR__"lgtxxe"); 
                if (ob) {
                inv = deep_inventory(ob);
                if( sizeof(inv) > 0 ) {
                    foreach( object ob3 in inv ) {
                                if( playerp(ob3) ) {
                                    tell_object(me,NOR"你再等等吧，現在"+query("name",ob3)+NOR+"正在"+HIC+query("short",ob)+NOR+"全力闖關中！\n"NOR); 
                                    me->start_busy(3);
                                    return -1;
                                }
                        }
                }
                }
                if (ob) destruct(ob);
                load_object(__DIR__"lgtxxe.c")->create();
                        }
                
                        if (dir == "northup") {
                ob = find_object(__DIR__"lgtxxn"); 
                if (ob) {
                inv = deep_inventory(ob);
                if( sizeof(inv) > 0 ) {
                    foreach( object ob3 in inv ) {
                                if( playerp(ob3) ) {
                                    tell_object(me,NOR"你再等等吧，現在"+query("name",ob3)+NOR+"正在"+HIC+query("short",ob)+NOR+"全力闖關中！\n"NOR); 
                                    me->start_busy(3);
                                    return -1;
                                }
                        }
                }
                }
                if (ob) destruct(ob);
                load_object(__DIR__"lgtxxn.c")->create();
                        }
                
                        if (dir == "southup") {
                ob = find_object(__DIR__"lgtxxs"); 
                if (ob) {
                inv = deep_inventory(ob);
                if( sizeof(inv) > 0 ) {
                    foreach( object ob3 in inv ) {
                                if( playerp(ob3) ) {
                                    tell_object(me,NOR"你再等等吧，現在"+query("name",ob3)+NOR+"正在"+HIC+query("short",ob)+NOR+"全力闖關中！\n"NOR); 
                                    me->start_busy(3);
                                    return -1;
                                }
                        }
                }
                }
                if (ob) destruct(ob);
                load_object(__DIR__"lgtxxs.c")->create();
                        }

                        if (dir == "up") {
                ob = find_object(__DIR__"lgtxxu"); 
                if (ob) {
                inv = deep_inventory(ob);
                if( sizeof(inv) > 0 ) {
                    foreach( object ob3 in inv ) {
                                if( playerp(ob3) ) {
                                    tell_object(me,NOR"你再等等吧，現在"+query("name",ob3)+NOR+"正在"+HIC+query("short",ob)+NOR+"全力闖關中！\n"NOR); 
                                    me->start_busy(3);
                                    return -1;
                                }
                        }
                }
                }
                
                if (!query_temp("lgt/wantup", me)) {
                                                        set_temp("lgt/wantup", 1, me);
                                    tell_object(me,NOR"提示：你如果想通往up方向的塔，需要被扣除"+(string)UP_PRICE+"點泥潭幣的VIP服務費。確定的話，請再次up。\n"NOR); 
                                    me->start_busy(1);
                                    return -1;
                }
                
                        amount = MEMBER_D->db_query_member(me, "money"); 
                if( amount < UP_PRICE){ 
                     write(NOR + "你賬戶上沒有那麼多泥潭幣！\n" + NOR);  
                     return -1; 
                } 
                        //amount -= UP_PRICE; 
                                //amount = MEMBER_D->db_set_member(me, "money", amount);
                                //log_file("static/lgtup",sprintf("%s %s - %d $NT ， balance: %d $NT\n",TIME_D->replace_ctime(time()), query("id", me), UP_PRICE, amount));
                                MEMBER_D->db_pay_member(query("id", me), -UP_PRICE);
                                
                if (ob) destruct(ob);
                load_object(__DIR__"lgtxxu.c")->create();
                        }                

                delete_temp("lgt", me);//防止玩家沒有quit過
                if( query("lgt/entertime", me) == query("lgt/entertime") ) // 增加vip9特權，by Lonely
                        set("lgt/entertime2", query("lgt/entertime"), me);
                set("lgt/entertime", query("lgt/entertime"), me);
                set("lgt/can_die", CAN_DIE + ((dir == "up") ? 3 : 0), me);
                set("lgt/texp", 0, me);
                

                message_vision(YEL + "楊小邪嘿嘿一笑，悄悄塞給$N"+chinese_number(CAN_DIE + ((dir == "up") ? 3 : 0))+"張靈符。$N一溜煙跑上樓梯去了。\n" NOR, me);
                
                
        }
        
// //防止從塔上昏迷下來的玩家被揹走到up或out去暗害
//         inv = deep_inventory(me);
//         if( sizeof(inv) > 0 ) {
//                 foreach( object ob2 in inv ) {
//                         if( interactive(ob2) || userp(ob2) ) {
//                                 tell_object(me, NOR"你不能在大眾面前將其他玩家背來背去的。\n"NOR);
//                                 return -1;
//                         }
//                 }
//         }

        return ::valid_leave(me, dir);
}

void log_hero(object me, int i)
{
                int j;
        string msgs;
        
        set("lgt/owner/"+to_string(i), query("id", me));
        j = sizeof(query("lgt/owner"));
        msgs = query("msg_hero");
        if (!msgs) msgs = "";
        msgs += "  " + HIC + query("family/family_name", me) + query("family/title", me) + "-" + RED + query("name", me) + NOR + "(" + query("id", me) +")-" + HIG + query("short", environment(me)) + "  " + NOR;
        if (j % 2 == 0) msgs += "\n";
        set("msg_hero", msgs);
}


string look_pai(object me)
{
        int j;
        string msgsn = "\n";
        
        if ( time() - query("lgt/lookpai", me) < 10 ) return YEL"十三少林棍僧對你齊聲一喝，你趕緊低頭不敢再看，後背冷汗如雨...\n"NOR; 
        set("lgt/lookpai", time(), me);
        j = sizeof(query("lgt/owner"));
        if (j % 2 == 0) msgsn = "";
        return 
HIC + "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n" + NOR +
((!query("msg_hero")) ? "目前暫時還沒有人登上靈感塔並功成身退！\n" : query("msg_hero") ) + NOR + msgsn + 
HIC + "※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n" + NOR + query("lgt/timesign") + NOR
;
}

