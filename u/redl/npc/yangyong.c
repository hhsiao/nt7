// This program is a part of NITAN MudLIB 
// redl 2013/8
// 5%賭神賭聖同時發作

#include <ansi.h>
#define CHANL_NAME "auc"
#define CHARM_BASEFILE "/clone/goods/tianshi-charm"
#define DEBUG 0
#define BET_ME 1        //暫且不開放，懲罰沒有計算好。而且氣氛不友好

inherit NPC;

int a_amount = 0, a_n1, a_n2, b_n1, b_n2, itmp, slv, sexp, spot, smar, sper;
string a_file, a_id, b_id, a_name, b_name, ob_name;
object usra, usrb;

void imp_sk(object me)
{
        if (!random(5)) {
                if (!random(3)) {
                        if (me->query_skillo("du-shen", 1) < 1000) me->improve_skill("du-shen", 200 + 2 * query("level", me)); 
                } else {
                        if (me->query_skillo("du-sheng", 1) < 1000) me->improve_skill("du-sheng", 200 + 2 * query("level", me)); 
                }
        }
}

int query_ln(object me)
{
        int tim = query("yangyong/learn/time", me);
        int num = query("yangyong/learn/num", me);
        
        if (undefinedp(tim) || !tim || tim!=time() / 86400) {
                tim = time() / 86400;
                num = 0;
                set("yangyong/learn/time", tim, me);
                set("yangyong/learn/num", num, me);
        }
        return num;
}

void add_ln(object me)
{
        addn("yangyong/learn/num", 1, me);
        tell_object(me, NOR + "你今天賭博" + chinese_number(query("yangyong/learn/num", me)) + "次了。\n" + NOR);
}

int random2 (int i)
{
        return (random(i)+uptime()) % i;
}

int rdm()
{
        object me, ene;
        object room = environment();
        int lv1, lv2, stp = query("stp_current");
        
        if (stp && usra && usrb) {
                if (stp==1) {
                        me = usra;
                        ene = usrb;
                } else if (stp==2) {
                        me = usrb;
                        ene = usra;
                } else if (stp==3) {
                        me = usra;
                        ene = usrb;
                } else if (stp==4) {
                        me = usrb;
                        ene = usra;
                } 
                
                if (stp==1 || stp==2) {
                        lv1 = me->query_skillo("du-sheng", 1);
                        lv2 = ene->query_skillo("du-sheng", 1);
                        if (lv1 && !random(4)) {
                                tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "桀桀桀地冒出幾聲陰笑，\n然後慢慢吐出口氣道：賭～～啊～～～\n" + NOR);
                                if (random(lv2*3) > lv1) {
                                        tell_room(room, NOR + CYN + query("name", ene) + NOR + CYN + "中食指輕揉雙太陽穴，猛地睜大眼睛衝著" + query("name", me) + NOR + CYN + "一盯。\n" + NOR);
                                        tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "噗地湧上一口鮮血，又強忍著內傷吞了回去。\n" + NOR);
                                        return random2(6);
                                } else {
                                        tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "繼續怪笑道：～啊～～～～聖～～\n" + NOR);
                                        return 6;
                                }
                        }
                } else if (stp==3 || stp==4) {
                        lv1 = me->query_skillo("du-shen", 1);
                        lv2 = ene->query_skillo("du-shen", 1);
                        if (lv1 && !random(5)) {
                                tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "悠閒地嚼著巧克力，\n手指上的戒指卻偷偷對著骰子一晃...\n" + NOR);
                                if (random(lv2*3) > lv1) {
                                        tell_room(room, NOR + CYN + query("name", ene) + NOR + CYN + "皺皺眉，拿起嘴裡銜著的大雪茄，對" + query("name", me) + NOR + CYN + "劈臉一噴。\n" + NOR);
                                        tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "被嗆得咳嗽不止，氣急指著" + query("name", ene) + NOR + CYN + "道：你～～\n" + NOR);
                                        return random2(6);
                                } else {
                                        tell_room(room, NOR + CYN + query("name", me) + NOR + CYN + "臉上露出賭神一樣的招牌微笑。\n" + NOR);
                                        if (stp==3) return a_n1;
                                        if (stp==4) return b_n1;
                                }
                        }
                }
        }
        
        return random2(6) + 1;
}

void display_bet(int i, int j)
{
        string str;
        object room = environment();
        switch (i)
        {
        case 1:
                str = ((j) ? RED : HIW) + 
"┌───┐\n"+
"│　　　│\n"+
"│　●　│\n"+
"│　　　│\n"+
"└───┘\n" + NOR;
                break;
        case 2:
                str = ((j) ? RED : HIW) + 
"┌───┐\n"+
"│　　　│\n"+
"│●　●│\n"+
"│　　　│\n"+
"└───┘\n" + NOR;
                break;
        case 3:
                str = ((j) ? RED : HIW) + 
"┌───┐\n"+
"│●　　│\n"+
"│　●　│\n"+
"│　　●│\n"+
"└───┘\n" + NOR;
                break;
        case 4:
                str = ((j) ? RED : HIW) + 
"┌───┐\n"+
"│●　●│\n"+
"│　　　│\n"+
"│●　●│\n"+
"└───┘\n" + NOR;
                break;
        case 5:
                str = ((j) ? RED : HIW) + 
"┌───┐\n"+
"│●　●│\n"+
"│　●　│\n"+
"│●　●│\n"+
"└───┘\n" + NOR;
                break;
        case 6:
                str = ((j) ? RED : HIW) + 
"┌───┐\n"+
"│●　●│\n"+
"│●　●│\n"+
"│●　●│\n"+
"└───┘\n" + NOR;
                break;
        }
        tell_room(room,str + "(" + (string)i + ")點\n" + NOR);
}

void do_return()
{
        object objb, pobj;
        
        remove_call_out("do_return");
        if (a_id && b_id)
        {
                if (a_id!="" && b_id!="" && a_file!="me") return;
        }
        
        if (a_file=="me") {
            pobj = find_player(a_id);
                if (pobj)
                {
                                pobj->stop_busy();
               
                                        set_temp("yangyong/time_start", time() - 20, pobj);
                }
                message_vision("$N不耐煩地說：" + a_name + "，都兩分鐘過去了也沒人來賭，你這次的小命算是保住了。\n", this_object(), pobj);
        }
        else {
                objb = new(a_file);
            pobj = find_player(a_id);
                itmp = objb->query_amount();
                if (pobj)
                {
                                pobj->stop_busy();
                        if( !itmp )
                        {
                        objb->move(pobj);
                        }
                        else
                        {
                        objb->set_amount(a_amount);
                        objb->move(pobj);
                        }
                
                                        set_temp("yangyong/time_start", time() - 20, pobj);
                }
                message_vision("$N不耐煩地說：" + a_name + "，都兩分鐘過去了也沒人來賭，" + ob_name + NOR + "還給你。\n", this_object(), pobj);
        }
        
        log_file("static/yangyong", sprintf("  -%s(%s)獲得了退還。\n",  a_name, a_id));
        a_amount = 0;
        a_id = b_id = "";
}

void do_end(string id)
{
        object objb, pobj;

        remove_call_out("do_return");
        objb = new(a_file);
        pobj = find_player(id);
        itmp = objb->query_amount();
        if (pobj)
        {
                if( !itmp )
                {
                        objb->move(pobj);
                        new(a_file)->move(pobj);
                }
                else
                {
                        objb->set_amount(a_amount * 2);
                        objb->move(pobj);
                }
        }
}

void do_kill(object target, object me)
{
        mapping ob; 
        object *obs;
        int icharm = 0;
        
        //暫時移除所有的天師符
        obs = all_inventory(target); 
                if (sizeof(obs) > 0) 
                { 
                        obs = obs[0..<1]; 
                        foreach (ob in obs) {
                                if (base_name(ob)==CHARM_BASEFILE) {
                                        destruct(ob); 
                                        icharm += 1;
                                }
                        }
                } 
        
        for(int i = a_amount; i > 0; i--) {     
                set_temp("die_reason", "因為賭命輸給" + query("name",me) + "而亡", target);
                target->die();
                target->reincarnate();
                target->move(environment(me));
                addn("combat_exp", sexp, me);
                addn("potential", spot, me);
                addn("experience", smar, me);
                CHANNEL_D->channel_broadcast(CHANL_NAME, NOR + query("name", me) + NOR + "從" + query("name", target) + NOR + "的屍體上獲得了" + 
                        "經驗:" + sexp + "，" + 
                        "潛能:" + spot + "，" + 
                        "體會:" + smar + "。\n" + NOR);
                log_file("static/yangyong", sprintf("  -經驗%d、潛能%d、體會%d。\n",  sexp, spot, smar));
                sexp /= 2;
                spot /= 2;
                smar /= 2;
        }
        
        for(int j = icharm; j > 0; j--) {       
                new(CHARM_BASEFILE)->move(target);
        }       
}

int do_start(int step)
{
        string jgmsg1, jgmsg2;
        usra->start_busy(999);
        usrb->start_busy(999);
        remove_call_out("do_start");
        switch(step)
        {
                case 0:
                                message_vision("$N大聲道：擲骰子現在開始。\n", this_object());
                                                                if (a_file=="me") {
                                                                        sper = 20;//獎勵等於兩者之和，除以20倍。不怕大米餵養，因為無法保證主id就一定會贏
                                                                        slv = abs((query("level",usra)) - (query("level",usrb)));//雙方的等級差，越大獎勵越低
                                                                        if (DEBUG) CHANNEL_D->channel_broadcast("wiz", NOR + "等級差:" + slv + "\n" + NOR);
                                                                        if ( (query("level",usra) / 10) < slv || (query("level",usrb) / 10) < slv ) sper *= 2;//再除以2
                                                                        if ( (query("level",usra) / 5) < slv || (query("level",usrb) / 5) < slv ) sper *= 2;//再除以2
                                                                        if ( (query("level",usra) / 2) < slv || (query("level",usrb) / 2) < slv ) sper *= 128;
                                                                        sexp = (query("combat_exp",usra));
                                                        spot = (query("potential", usra)-query("learned_points", usra));
                                                        smar = (query("experience", usra)-query("learned_experience", usra));
                                                                        sexp += (query("combat_exp",usrb));
                                                        spot += (query("potential", usrb)-query("learned_points", usrb));
                                                        smar += (query("experience", usrb)-query("learned_experience", usrb));
                                                        sexp /= sper;
                                                        spot /= sper;
                                                        smar /= sper;
                                                                        if (DEBUG) CHANNEL_D->channel_broadcast("wiz", NOR + "獎勵比例:1/" + sper + "  經驗:" + sexp +  "  潛能:" + spot +  "  體會:" + smar + "\n" + NOR);
                                                                }
                                break;
                case 1:
                        tell_room(environment(), RED + a_name + NOR + "輕輕一扔，骰子滴溜溜一轉：\n");
                        set("stp_current", 1);
                        display_bet(a_n1 = rdm(), 1);
                                break;
                case 2:
                        tell_room(environment(), HIW + b_name + NOR + "輕輕一扔，骰子滴溜溜一轉：\n");
                        set("stp_current", 2);
                        display_bet(b_n1 = rdm(), 0);
                                break;
                case 3:
                        tell_room(environment(), RED + a_name + NOR + "對著骰子哈了口氣，狠狠地一扔：\n");
                        set("stp_current", 3);
                        display_bet(a_n2 = rdm(), 1);
                                break;
                case 4:
                        tell_room(environment(), HIW + b_name + NOR + "對著骰子哈了口氣，狠狠地一扔：\n");
                        set("stp_current", 4);
                        display_bet(b_n2 = rdm(), 0);
                                break;
                                default:
                                if (a_n1 == a_n2) {
                                        jgmsg1 = "一對" + chinese_number(a_n1);
                                        a_n1 = (a_n1 + a_n2) * 100;
                                }
                                else {
                                        a_n1 = a_n1 + a_n2;
                                                                             jgmsg1 = chinese_number(a_n1) + "點大";
                                }
                                        
                                if (b_n1 == b_n2) {
                                        jgmsg2 = "一對" + chinese_number(b_n1);
                                        b_n1 = (b_n1 + b_n2) * 100;
                                }
                                else  {
                                        b_n1 = b_n1 + b_n2;
                                        jgmsg2 = chinese_number(b_n1) + "點大";
                                }

                                if (a_n1 > b_n1) {
                                        message_vision("$N宣佈：" + jgmsg1 + "，" + RED + a_name + NOR + "得勝。\n" + NOR, this_object());
                                        log_file("static/yangyong", sprintf("  -%s(%s)勝利。\n",  a_name, a_id));
                                        if (a_file=="me") {
                                                do_kill(usrb, usra);
                                        } 
                                        else {
                                                do_end(a_id);
                                                message_vision("$N拿出一些" + ob_name + NOR + "交給" + a_name + "。\n" + NOR, this_object());
                                                CHANNEL_D->channel_broadcast(CHANL_NAME, query("name") + NOR + "拿出一些" + ob_name + NOR + "交給獲勝的" + a_name + "。\n" + NOR);
                                        }
                                        if (usra) imp_sk(usra);
                                } else if (a_n1 < b_n1) {
                                        message_vision("$N宣佈：" + jgmsg2 + "，" + HIW + b_name + NOR + "得勝。\n" + NOR, this_object());
                                        log_file("static/yangyong", sprintf("  -%s(%s)勝利。\n",  b_name, b_id));
                                        if (a_file=="me") {
                                                do_kill(usra, usrb);
                                        } 
                                        else {
                                                do_end(b_id);
                                            message_vision("$N拿出一些" + ob_name + NOR + "交給" + b_name + "。\n" + NOR, this_object());
                                                CHANNEL_D->channel_broadcast(CHANL_NAME, query("name") + NOR + "拿出一些" + ob_name + NOR + "交給獲勝的" + b_name + "。\n" + NOR);
                                            }
                                        if (usrb) imp_sk(usrb);
                                } else {
                                        message_vision("$N高聲道：平局，重新擲骰子。\n", this_object());
                                        step = 0;
                                        break;
                                }
                                        
                                a_amount = 0;
                                a_id = b_id = "";
                                set_temp("yangyong/time_start", time(), usra);
                                set_temp("yangyong/time_start", time(), usrb);
                                                        usra->stop_busy();
                                                        usrb->stop_busy();
                                add_ln(usra);                        
                                add_ln(usrb);
                                return 1;
                }
        step += 1;
        call_out("do_start", 2, step);
        return 1;
}

int do_accept()
{
        object ob, me = this_player();
        if (a_file!="me") {
                return 0;
        }
        if (a_id != query("id", me)) {
                write("這局賭博不關你的事！\n");
                return 1;
        }
        ob = find_player(b_id);
        if (!ob || !userp(ob))  {
                write("對象已經不在遊戲裡了！\n");
                return 1;
        }
        if (environment(ob) != environment(me)) {
                write("該對象不在這個房間裡了！\n");
                return 1;
        }
        ob->start_busy(999);
        me->command("nod " +  b_id + " 好吧，陪你玩一次。");
        
                //提醒一下觀眾
                CHANNEL_D->channel_broadcast(CHANL_NAME, NOR + b_name + NOR + "押上" + RED + chinese_number(a_amount) + "條命" + NOR + "奉陪。\n" + HIB
                        + "  - 等級：" + (query("level",ob)) + "\n"
                        + "  - 經驗：" + (query("combat_exp",ob)) + "\n"
                        + "  - 潛能：" + (query("potential", ob)-query("learned_points", ob)) + "\n"
                        + "  - 體會：" + (query("experience", ob)-query("learned_experience", ob)) + "\n"
                        + NOR);
                                log_file("static/yangyong", sprintf("  -%s(%s)奉陪，等級%d、經驗%d、潛能%d、體會%d。\n",  b_name, b_id, (query("level",ob)), (query("combat_exp",ob)), (query("potential", ob)-query("learned_points", ob)), (query("experience", ob)-query("learned_experience", ob)))); 

                                set("yangyong/time_start", time());
                                remove_call_out("do_return");
                call_out("do_start", 3, 0);

        return 1;       
}

int do_no()
{
        object me = this_player();
        if (a_file!="me") {
                return 0;
        }
        if (a_id != query("id", me)) {
                write("這局賭博不關你的事！\n");
                return 1;
        }
        if (!b_id) {
                write("沒有人想和你賭博呀！\n");
                return 1;
        }
        me->command("shake 我對你沒興趣呀");
        b_id = "";
        
        return 1;
}

int do_bet(string arg)
{
        object me;
        object ob;
        object nob;
        object *inv;
        string my_id, units;
        int amount;
        int value;
        int res;
        int max_count;
        int i;
        mixed ns;

        if( !arg ) {
                return notify_fail("你要賭什麼？\n");
        }
        
                if ((time() - query("yangyong/time_start")) < 30) 
        {
                write(CYN + name() + "不耐煩道：“等會兒，我忙著呢。”\n" NOR);
                return 1;
        }

        me = this_player();
       
        if(!interactive(me) || !playerp(me) || me->is_busy()) {
                return notify_fail("你正忙著呢。\n");
        }
        
        if (query_ln(me)>=30) {
                write(CYN + name() + "氣憤道：“你今天都壓３０次了還來？戒一戒賭吧。”\n" NOR);
                return 1;
        }
        
        if (query("online_time", me) < 43200) {
                write(CYN + name() + "不耐煩道：“你才多大點呀？毛都沒長齊也想玩黃賭毒。”\n" NOR);
                return 1;
        }
                
                if ((time() - query_temp("yangyong/time_start", me)) < 35) 
        {
                write(CYN + name() + "不耐煩道：“等會兒，你才剛賭過吧？”\n" NOR);
                return 1;
        }

                if (a_id && b_id) {
                        if (a_id!="" && b_id!="") {
                                write(CYN + name() + "說道：“再等一等吧，有兩個人正在玩呢。”\n" NOR);
                            return 1;
                        }
                }
       
        if( sscanf(arg, "%d %s", amount, arg) != 2 )
                // not indicate the amount of the goods
                amount = 1;

        if( amount < 1 )
        {
                write(CYN + name() + "疑惑的問道：“沒見過這種賭法，你到底想賭幾件呢？”\n" NOR);
                return 1;
        }


        if (arg == "me") {//賭命
                
                if (!BET_ME)
                {
                write(CYN + name() + "皺眉道：賭命暫時不開放。”\n" NOR);
                return 1;
                }

        if( amount > 10 )
        {
                write(CYN + name() + "大驚失色道：“你這也太狠了吧？我現在最多支持賭十條命。”\n" NOR);
                return 1;
        }
       
        if (a_amount) {

                        if (query("id", me)==a_id) {
                                write(CYN + name() + "嗤笑道：“自己和自己拼命，你是白痴吧？”\n" NOR);
                                return 1;
                        }
                        
                        if (a_file!="me") {
                                write(CYN + name() + "眼淚都笑出來了說：“我看" + a_name + "似乎不想和你玩命啊！”\n" NOR);
                                return 1;
                        }

                        if (amount!=a_amount) {
                                write(CYN + name() + "奸笑著說：“怎麼你押的性命數目和" + a_name + "的不一致啊？”\n" NOR);
                                return 1;
                        }

                        message_vision("$N惡狠狠地大吼：我來奉陪，" + a_name + "你敢答應(accept)嗎？。\n",
                                       me, this_object());

                b_id = query("id", me);
                usrb = me;
                b_name = query("name", me);
                set_temp("yangyong/time_start", time() + 25, me);

                                tell_object(find_player(a_id), HIG + name() + HIG +  "偷偷告訴你：" + b_name + HIG + "的情報... \n" + HIB
                        + "  - 等級：" + (query("level",me)) + "\n"
                        + "  - 經驗：" + (query("combat_exp",me)) + "\n"
                        + "  - 潛能：" + (query("potential", me)-query("learned_points", me)) + "\n"
                        + "  - 體會：" + (query("experience", me)-query("learned_experience", me)) + "\n" + HIG
                        + "如果不想賭可以輸入(no)。\n"
                        + NOR);
               
        } else {

                        message_vision("$N大聲對$n說道：我要押上自己的" + chinese_number(amount) + "條命。\n",
                                       me, this_object());
                                                                       
                a_id = query("id", me);
                usra = me;
                a_name = query("name", me);
                a_amount = amount;
                a_file = "me";
                write(CYN + name() + "對你說：“現在後悔已經沒用了，安心等候結果吧。”\n" NOR);
                me->start_busy(999);
                call_out("do_return", 120);
                //提醒一下觀眾
                CHANNEL_D->channel_broadcast(CHANL_NAME, NOR + a_name + NOR + "押上" + RED + chinese_number(a_amount) + "條命" + NOR + "在羊勇的賭檔上等待挑戰。\n" + HIB
                        + "  - 等級：" + (query("level",me)) + "\n"
                        + "  - 經驗：" + (query("combat_exp",me)) + "\n"
                        + "  - 潛能：" + (query("potential", me)-query("learned_points", me)) + "\n"
                        + "  - 體會：" + (query("experience", me)-query("learned_experience", me)) + "\n"
                        + NOR);
                                log_file("static/yangyong", sprintf("(%s)%s(%s)在羊勇押了%d條命，等級%d、經驗%d、潛能%d、體會%d。\n",  ctime(time()), a_name, a_id, a_amount, (query("level",me)), (query("combat_exp",me)), (query("potential", me)-query("learned_points", me)), (query("experience", me)-query("learned_experience", me)))); 

        }
                
                return 1;
        }
        
        ob = present(arg, me);
        if( !ob )
        {
                inv = all_inventory(me);
                for( i = 0; i < sizeof(inv); i++ )
                {
                        if( filter_color(inv[i]->name(1)) == arg )
                        {
                                ob = inv[i];
                                break;
                        }
                }
        }

        if ( !objectp(ob) )
        {
                write("你身上沒有這種東西啊！\n");
                return 1;
        }

        max_count = ob->query_amount();
        if( !max_count )
        {
                // not combined object
                if( amount > 1 )
                {
                        write(ob->name() + "這種東西不能拆開來賭。\n");
                        return 1;
                }
                max_count = 1;
        } else
        {
                // is combined object
                if( amount > max_count )
                {
                        write("你身上沒有這麼多" + ob->name() + "。\n");
                        return 1;
                }
        }


        if( ob->is_character() )
        {
                write(CYN + name() + "驚訝道：“這東西也能賭？！”\n" NOR);
                return 1;
        }

        if( query("unique", ob)
        ||  query("no_pawn", ob)
        ||  query("replica_ob", ob) )
        {
                write(CYN + name() + "搖搖頭，道：“這種東西我"
                      "不識貨，不敢接。”\n" NOR);
                return 1;
        }

        if( query("no_drop", ob) ||
            (ns = query("no_sell", ob)) )
        {
                write(CYN + name() + "搖搖頭，道：“這種東西我"
                      "不識貨，不敢接。”\n" NOR);
                return 1;
        }

        if( query("food_supply", ob)
        ||  ob->is_liquid() )
        {
                write(CYN + name() + "不屑道：“嘿嘿，剩菜剩飯留給"
                      "您自己用吧。”\n" NOR);
                return 1;
        }

        if( query("shaolin", ob) )
        {
                write(CYN + name() + "驚道：“小的膽子很小，可"
                      "不敢賭少林廟產。”\n" NOR);
                return 1;
        }

        if( query("mingjiao", ob) )
        {
                write(CYN + name() + "忙搖頭道：“小的只有一個腦袋，可"
                      "不敢賭魔教的東西。”\n" NOR);
                return 1;
        }

        if( sscanf(base_name(ob), "/data/%*s") )
        {
                write(CYN + name() + "說道：“厚道點，被綁定過的東西不能拿來騙人啊。”\n" NOR);
                return 1;
        }
        
        //"/inherit/template/armor/armor"
        if( sscanf(base_name(ob), "/inherit/template/%*s") )
        {
                write(CYN + name() + "說道：“這種東西不能賭。”\n" NOR);
                return 1;
        }


        if( query("consistence", ob) )
                value = value * query("consistence", ob) / 100;

        if( max_count > 1 )
        {
                if( query("base_value", ob) * amount / amount != query("base_value", ob) )
                {
                        write(CYN + name() + CYN "大驚失色道：這麼大一筆生意？我"
                              "可不好做。\n" NOR);
                        return 1;
                }
                value = query("base_value", ob) * amount;
        }
        else
                value = query("value", ob);

        if( value < 2 ) {
                write(CYN + name() + "隨手一扔，道：" + query("name", ob) +
                      CYN "一文不值！\n" NOR);
                                return 1;
        }
        
                if( query("bind_owner", ob) || query("bindable", ob) )
                {
                        write(CYN + name() + "說道：“厚道點，被綁定過的東西不能拿來騙人啊。”\n" NOR);
                        return 1;
                }
                
                if (a_amount) {
                        if (query("id", me)==a_id) {
                                write(CYN + name() + "嗤笑道：“自己和自己玩，你沒發燒吧？”\n" NOR);
                                return 1;
                        }
                        
                        if (base_name(ob)!=a_file) {
                                write(CYN + name() + "奸笑著說：“怎麼你拿出來的東西和對方的不一致啊？”\n" NOR);
                                return 1;
                        }

                        if (amount!=a_amount) {
                                write(CYN + name() + "奸笑著說：“怎麼你拿出來的數目和對方的不一樣啊？”\n" NOR);
                                return 1;
                        }
                        
                }

                if (query("base_unit", ob)) {
                        units = query("base_unit", ob);
                }
                else if (query("unit", ob)) {
                        units = query("unit", ob);
                }
                else {
                        units = "個";
                }

        message_vision("$N拿出" + chinese_number(amount) + units +
                                       query("name", ob) + "(" + query("id", ob) + ")" + "交給$n。\n",
                                       this_player(), this_object());
        
        if (a_amount) {
                b_id = query("id", me);
                usrb = me;
                b_name = query("name", me);
                                set("yangyong/time_start", time());
                                remove_call_out("do_return");
                call_out("do_start", 3, 0);
                                log_file("static/yangyong", sprintf("  -%s(%s)奉陪。\n",  b_name, b_id)); 
        } else {
                a_id = query("id", me);
                usra = me;
                a_name = query("name", me);
                a_amount = amount;
                a_file = base_name(ob);
                ob_name = query("name", ob);
                call_out("do_return", 120);
                //提醒一下觀眾
                CHANNEL_D->channel_broadcast(CHANL_NAME, NOR + a_name + NOR + "拿出" + chinese_number(a_amount) + units + ob_name + "(" + query("id", ob) + ")" + NOR + "在羊勇的賭檔上等待挑戰。\n" + NOR);
                        log_file("static/yangyong", sprintf("(%s)%s(%s)在羊勇押了%d個%s(%s)。\n",  ctime(time()), a_name, a_id, a_amount, ob_name, a_file)); 
        }
        
                if( max_count == amount ) {
                        destruct(ob);
                }
                else
                {
                        ob->add_amount(-amount);
                }
                
                write(CYN + name() + "對你說：“超重不賠，重啟不賠，不準亂走，自求多福吧。”\n" NOR);
                me->start_busy(999);                
        return 1;
}




int ask_nt()
{
                int amount;
        object me = this_player();
        
                if(!interactive(me) || !playerp(me) || me->is_busy()) return notify_fail("你正忙著呢。\n");
        
        if( query("online_time", me) < 3600){
                tell_object(me,CYN + query("name") + CYN + "深情地看了你一眼說：你是新來的吧..吧...？\n"+ NOR); 
                return 1;
        }      

        amount = MEMBER_D->db_query_member(me, "money");
        
        if( amount < 102){
                tell_object(me,CYN + query("name") + CYN + "面孔扭曲地說：你賬戶上沒有102 $NT來兌換呀！\n"+ NOR); 
                return 1;
        }
        
        if (!query_temp("yangyong/nt", me)) {
                tell_object(me,CYN + query("name") + CYN + "親切地說：確定要兌換請再次輸入<ask yang yong about NT>。\n"+ NOR); 
                set_temp("yangyong/nt", 1, me);
                return 1;
        }

                me->start_busy(2);

                amount -= 102;
        if (!MEMBER_D->db_set_member(me, "money", (amount)))
        {
                write("兌換失敗，請與本站ADMIN聯繫！\n");
                return 1;
        }
        write(HIG + "羊勇悄悄告訴你：會員賬戶餘額: (" + amount + ") $NT。\n" + NOR);

        new(__DIR__"obj/ntb")->move(me);
        message_vision(YEL + "$N" + NOR + YEL+ "從" + query("name") + NOR + YEL+ "手裡接過一張百元泥潭幣。\n" + NOR, me);        
        log_file("static/yangyong3",sprintf("%s %s 100 $NT -> 百元泥潭幣, 賬戶餘 %d $NT\n",TIME_D->replace_ctime(time()), query("id", me), amount));
       
        return 1;
}      

void create()
{
        set_name(NOR "羊勇" NOR, ({ "yang yong", "yang" }));
         set("nickname", HIK "黑心老闆" NOR);
        set("long", @LONG
雲南邊境上走私販毒的奸商，退出江湖後在公共聊天室附近坑人搞賭。
LONG);
        set("gender", "男性" );
        set("age", 38);
        set("attitude", "friendly");
        set("max_jing", 50000);
        set("max_qi", 50000);
        set("max_jingli", 50000);
        set("jingli", 50000);
        set("max_neili", 50000);
        set("neili", 50000);
        set("jiali", 350);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("per", 13);
        set("combat_exp", 1333000);

        set("inquiry", ([
                "nt"   : (: ask_nt :),
                "NT"   : (: ask_nt :),
                "賭博說明"     : "支持兩個玩家對賭，使用<bet 數量 id名>，就可以把物品押上來。\n"+NOR,
                "兌換說明" : "如果member賬戶上有102 $NT，可以<ask yang yong about NT>兌換成一張百元泥潭幣。\n"+NOR,
                "賭命說明"     : "支持兩個玩家對賭，使用<bet 數量 me>，就可以押上幾條性命，天師符在此無效。\n"+NOR,
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();

}



void init()
{
        if (! interactive(this_player())) return;
        add_action("do_bet", "bet");
        add_action("do_accept", "accept");
        add_action("do_no", "no");
}



