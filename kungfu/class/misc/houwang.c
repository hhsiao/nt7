//開始閱讀文件：/kungfu/class/misc/houwang.c
//redl 2014
#include <ansi.h>
inherit NPC;

int is_ghost()
{
        return query("rnd_moved");
}

void rape()
{
        string names = "";
        object *obs;
        object me = this_object();
        int lv = query("level");
        if (lv<30) return;
        if (query("short", environment())=="水簾洞") return ;
        if (random(10000)>(lv*lv) && (query("n_flee") > 1800)) return;
        if (random(70-lv) && (query("n_flee") > 1800)) return;
                //擄掠
                obs = filter_array(query_enemy(),
                           (: playerp($1) &&
                           living($1)
                           :));
                if (obs && arrayp(obs) && sizeof(obs)) {
                        delete("chat_chance");
                        message_vision(YEL "只見$N突然臉上露出邪惡的笑容，嘎嘎大叫道：筋斗雲，疾！\n" NOR, me);
                        message_vision(CYN "金光遍地中，$N" NOR CYN "被一朵烏雲裹走了......\n" NOR, me);
                        me->move("/u/redl/teleport/huaguo");
                        me->start_busy(3);
                        foreach(object tob in obs) {
                                if (!userp(tob)) continue;
                                message_vision(CYN "金光遍地中，$N" NOR CYN "被一朵烏雲裹走了......\n" NOR, tob);
                                tob->move("/u/redl/teleport/huaguo");
                                tob->start_busy(3);
                                me->kill_ob(tob);
                                if (names!="") names +="、";
                                names += query("name", tob);
                        }
                        CHANNEL_D->channel_broadcast("rumor", "某人(Someone.)：聽說"+query("name")+"把"+names+"擄掠到水簾洞去了，不知道想做什麼...\n" NOR);
                }
}

int level_up()
{
        int /*tmp,*/ lv, ef;
//      object *obs;
        object me = this_object();
        string oldname = query("name", me);

        addn("level", 1);
        lv = query("level");
        set("title", HIC + chinese_number(lv) + "級" + NOR);    
        if (lv >= 90) {
        set_name("鴻蒙天猴", ({ "hou wang", "hou", "wang", "monkey" }));
            new("/d/emei/obj/pantao")->move(me, 1);
            new("/d/emei/obj/pantao")->move(me, 1);
            ef = 20;
    }
        else if (lv >= 80) {
        set_name("不動神猴", ({ "hou wang", "hou", "wang", "monkey" }));
            new("/d/emei/obj/pantao")->move(me, 1);
            if (!random(2)) new("/d/emei/obj/pantao")->move(me, 1);
            ef = 21;
    }
        else if (lv >= 70) {
        set_name("金剛頑猴", ({ "hou wang", "hou", "wang", "monkey" }));
            new("/d/emei/obj/pantao")->move(me, 1);
            if (!random(3)) new("/d/emei/obj/pantao")->move(me, 1);
            ef = 22;
    }
        else if (lv >= 60) {
        set_name("混世石猴", ({ "hou wang", "hou", "wang", "monkey" }));
            new("/d/emei/obj/pantao")->move(me, 1);
            if (!random(4)) new("/d/emei/obj/pantao")->move(me, 1);
            ef = 23;
    }
        else if (lv >= 50) {
        set_name("鬥戰勝佛", ({ "hou wang", "hou", "wang", "monkey" }));
            new("/d/emei/obj/pantao")->move(me, 1);
            if (!random(5)) new("/d/emei/obj/pantao")->move(me, 1);
            ef = 24;
    }
        else if (lv >= 40) {
        set_name("齊天大聖", ({ "hou wang", "hou", "wang", "monkey" }));
            if (lv / 2 * 2 == lv)       new("/d/emei/obj/pantao")->move(me, 1);
            if (!random(6)) new("/d/emei/obj/pantao")->move(me, 1);
            ef = 43;
    }
        else if (lv >= 30) {
        set_name("美猴王", ({ "hou wang", "hou", "wang", "monkey" }));
            if (lv / 3 * 3 == lv)       new("/d/emei/obj/pantao")->move(me, 1);
            if (!random(7)) new("/d/emei/obj/pantao")->move(me, 1);
            ef = 56;
    }
        else if (lv >= 20) {
        set_name("大猿王", ({ "hou wang", "hou", "wang", "monkey" }));
            if (lv / 4 * 4 == lv)       new("/d/emei/obj/pantao")->move(me, 1);
            ef = 76;
    }
        else if (lv >= 10) {
        set_name("山嶽巨猿", ({ "hou wang", "hou", "wang", "monkey" }));
            if (lv / 5 * 5 == lv)       new("/d/emei/obj/pantao")->move(me, 1);
            ef = 96;
    }
        else if (lv >= 1) {
        set_name("巨猿", ({ "hou wang", "hou", "wang", "monkey" }));
            if (lv / 5 * 5 == lv)       new("/d/emei/obj/pantao")->move(me, 1);
            ef = 105;
    }
    if ((lv / 10 * 10 == lv)) {
        CHANNEL_D->channel_broadcast("news", "聽說"+query("name")+"出現在"+query("short", environment())+"。\n" NOR);
                message_vision(append_color(BLINK + BCYN + HIY + "\n" + oldname + "在地上滾出老遠，突然撐起憤怒咆哮，$N出現在你面前。\n\n" + NOR, BLINK + HIY), me);
        }
        else
                message_vision(append_color(BCYN + HIY + "\n" + oldname + "在地上滾出老遠，翻身立起來猛然捶胸嚎叫不已。\n\n" + NOR, HIY), me);
                
        addn("str", 3 + random(2));
        addn("int", 1 + random(2));
        addn("con", 2 + random(2));
        addn("dex", 2 + random(2));
        addn("combat_exp", query("combat_exp") / 10);

        set_skill("cuff", me->query_skill("cuff", 1)*90/80);
        set_skill("mizong-houquan", me->query_skill("mizong-houquan", 1)*90/80);
        set_skill("parry", me->query_skill("parry", 1)*90/80);
        set_skill("dodge", me->query_skill("dodge", 1)*90/80);
        set_skill("force", me->query_skill("force", 1)*90/80);
        set_skill("martial-cognize", me->query_skill("martial-cognize", 1)*90/80);
        set_skill("force-cognize", me->query_skill("force-cognize", 1)*90/80);

                if (lv>=30) {
                        set_skill("shexing-lifan", me->query_skill("force-cognize", 1)/2 + random(me->query_skill("force-cognize", 1)/2));
                        map_skill("dodge", "shexing-lifan");
                        set_skill("never-defeated", me->query_skill("force-cognize", 1)/2 + random(me->query_skill("force-cognize", 1)/2));
                        map_skill("force", "never-defeated");

                }
                if (lv>=40) {
                        set_skill("count", lv * lv * 5);
                }
        map_skill("cuff", "mizong-houquan");
        map_skill("parry", "mizong-houquan");
                if (lv>=60) {
                        set_skill("jingang-buhuaiti", me->query_skill("force-cognize", 1)/5 + random(me->query_skill("force-cognize", 1)/5));
                        map_skill("parry", "jingang-buhuaiti");
                }
        prepare_skill("cuff", "mizong-houquan");

        set_temp("apply/attack",  query_temp("apply/attack")*83/80);
        set_temp("apply/defense", query_temp("apply/defense")*86/80);
        add_temp("apply/damage",  ef/5000);
        add_temp("apply/unarmed_damage", ef/5000);
        set_temp("apply/armor", ef/1000);

                set_temp("apply/add_freeze", lv / 5);//   : "冰凍",                       // weapon 終極兵器 冰凍-遲緩，減緩對方攻擊，攻擊pfm速度降低，無任何防禦，無躲閃，無招架，就是捱打
                set_temp("apply/add_forget", lv / 20);//   : "遺忘",                       // weapon 終極防具 遺忘-使對方忘記所有技能的絕招add_oblivion   
                set_temp("apply/add_weak", lv / 10);//     : "虛弱",                       // weapon 終極兵器
                set_temp("apply/add_busy", lv / 50);//     : "忙亂",                       // weapon 終極兵器
                set_temp("apply/avoid_freeze", lv - 5);// : "忽視冰凍",                   // armor/rings 終極防具
                set_temp("apply/avoid_weak", lv - 5);//   : "忽視虛弱",                   // armor/rings 終極防具
                set_temp("apply/avoid_busy", lv);//   : "忽視忙亂",                   // armor/rings 終極防具
                set_temp("apply/reduce_busy", lv);//  : "化解忙亂",                   // armor/rings 終極防具
                set_temp("apply/reduce_damage", lv / 2);//  : 化解傷害",                   // armor 終極防具 
                set_temp("apply/ap_power", lv);//  : "絕招攻擊力",         // weapon/rings
                set_temp("apply/dp_power", lv);//  : "絕招防禦力",         // armor
                set_temp("apply/da_power", lv / 10);//  : "絕招傷害力",         // weapon/rings
                set_temp("apply/avoid_defense", lv - 10);//  : "攻擊無視目標防禦",   // weapon/rings
                set_temp("apply/avoid_parry", lv - 10);//  : "攻擊無視目標招架",   // weapon/rings
                set_temp("apply/avoid_dodge", lv - 10);//  : "攻擊無視目標躲閃",   // weapon/rings
                set_temp("apply/avoid_force", lv - 10);//  : "攻擊無視內功防禦",   // weapon/rings
                set_temp("apply/avoid_attack", lv - 10);//  : "無視目標特殊攻擊",   // armor

        addn("max_neili", query("max_neili")*ef/500);
        set("neili", query("max_neili"));
        addn("max_jingli", query("max_jingli")*ef/500);
        set("jingli", query("max_jingli"));
        addn("max_jing", query("max_jing")*ef/100);
        set("jing", query("max_jing"));
        addn("max_qi", query("max_qi")*ef/100);
        set("qi", query("max_qi"));
        set("jiali", lv*lv*2);
        full_self();
        me->reset_action(); 
        //command("jiali max");
        if ((query("short", environment())!="水簾洞"))
                set("n_flee", 1800 + ((10 * lv < 600) ? (10 * lv) : 600));
        else 
                set("n_flee", 1800 + 120 * lv);
        if (lv>=60 && (random(100) < lv - 40)) {
                command("perform parry.protect");
        }
        return 1;
}

void add_enemlist(object me)
{
        object *owns;
        
        if( !me ) return;
        if (!playerp(me)) return;
                owns = query("ownlist");
                if (undefinedp(owns) || !owns || !sizeof(owns))
                        set("ownlist",  ({me}));
                else if (member_array(me, owns) < 0)
                        set("ownlist",  owns + ({me}));
}                

void remotekill_enemlist()
{
        string msg;
        object where, own, *owns;
        int damage = random(120) + 1;
        owns = query("ownlist");
        if (undefinedp(owns) || !owns || !sizeof(owns)) return;
        own = owns[random(sizeof(owns))];
        if (!own || !(where=environment(own))) return;
        if (strsrch(base_name(where), "/d/death/") != -1) return;
        if (query_temp("sleeped", own))  return; 
        if (environment(own) == environment()) return;
        message_vision(BLINK BCYN HIY "$N" HIY "從耳朵裡掏出根繡花針，迎風一晃無限長大，望虛空處一戳...\n" NOR, this_object()); 
        msg = BLINK BCYN HIY + (random(2) ? "天上":"雲中") + HIY + (random(2) ? "突然":"忽地") + 
                (random(2) ? "顯現":"凝聚出") + "一根巨柱直插而來，$N" + (random(2) ? "剛剛":"只來得及") + 
                (random(2) ? "認清":"看到") + HIW + (random(2) ? "『定海神針鐵.重一萬三千～～』":"『定海神針鐵.重一萬～～～』") + 
                HIY + "幾個大字...\n" + NOR;
        message_vision(msg, own);       
        own->receive_damage("qi", query("max_qi", own)*damage/100, this_object());
        own->receive_wound("qi", query("max_qi", own)*damage/100, this_object());
        COMBAT_D->report_status(own);
                       if (query("qi", own) < 0) {
                                set_temp("die_reason", "被" + query("name") + "用金箍棒捅死了", own);
                                own->die();
                        }
        if (random(6)) owns -= ({own});
        set("ownlist",  owns);
}

void heart_beat()
{
                string msg;
                object *enemies, enemy;
                object me = this_object();
                int damage, time;
                if (!objectp(environment())) return;
                if (query("rnd_moved")) {
                        me->random_move();
                        me->random_move();
                        me->random_move();
                        me->random_move();
                        me->random_move();
                        set("rnd_moved", 0);
                        if (query("doubi") && !random(2)) new(__FILE__)->move(environment());
            }
        if( query("level") && query("n_flee") < 2 ){
                        message_vision(CYN + query("name") + NOR + CYN + "嘿嘿笑道：罷，本大王去也...\n"+ NOR + 
                                                        YEL + query("name") + NOR + YEL + "說完，掐訣一個筋斗衝九霄而逝。\n" + NOR, me); 
                        destruct(this_object());                                                                            
                        return;
        }
        rape();
        addn("n_flee", -1);   
        if ( query("level") && (query("n_flee") / 180 * 180 == query("n_flee")) ) set("jiali", query("jiali") / 100 * 105);
        if (!random(12) == 1)
        {
            delete_temp("no_perform");
            delete_temp("no_exert");
        }
                if (!random(23 - (query("level")/5))) {
            me->stop_busy();
        }
        if ((query("short", environment())=="水簾洞"))
                        enemies = filter_array(all_inventory(environment()), (: query("id", $1) != "hou wang" &&
                                                                                                                        (!query("env/invisible", $1)) && 
                                                                                                                        $1->is_character() && living($1)
                                                                                                                 :));
        else 
                enemies = query_enemy();
        if (query_temp("smh_time")<time() && 
                !random(8 - ((!query("chat_chance")) ? (query("level")/10) : 0)) && 
                query("level") >= 40 && random(query("level")+1)>=40 && enemies && arrayp(enemies) && sizeof(enemies)) {
                set_temp("smh_time", time() + 2);
            msg = HIY "\n$N睜開火眼精睛射出一道弧形光線，沿著身前幾個方向一掃。\n" NOR;
            message_vision(append_color(msg, HIY), me);
            me->start_busy(2);
                foreach(enemy in enemies) {
                                if (enemy && objectp(enemy)) {
                        msg = HIR "$N全身燃起白晃晃的三昧真火，燒得是皮開肉綻。\n" NOR;
                        message_vision(append_color(msg, HIR), enemy);
                        damage = query("max_qi", enemy)/1000*query("level");
                        if (damage < 30000 * query("level")) damage = 30000 * query("level");
                        if (!playerp(enemy) && !random(8)) damage *= 1+random(20);
                        enemy->receive_damage("qi", damage, me);
                        enemy->receive_wound("qi", damage, me);
                        enemy->receive_damage("jing", damage / 2, me);
                        enemy->receive_wound("jing", damage / 2, me);
                        COMBAT_D->report_status(enemy);
                        if( !enemy->is_busy() ) enemy->start_busy(2);
                    }
                }
        }
        time = time();
        if( (time/5*5==time) && enemies && arrayp(enemies) && sizeof(enemies) )
                foreach(enemy in enemies) add_enemlist(enemy);
        if (!query("chat_chance") && (time/15*15==time)) {
                if (query("eff_qi")<query("max_qi")) addn("eff_qi", query("level") * 10000);
                if (query("qi")<query("eff_qi")) addn("qi", query("level") * 10000);
                if (query("eff_jing")<query("max_jing")) addn("eff_jing", query("level") * 10000);
                if (query("jing")<query("eff_jing")) addn("jing", query("level") * 10000);
                if (query("neli")<query("max_neili")) addn("neili", 1000000);
        }
        if (random(query("level"))>=33 && query("rk_time") < time()) {
                //set("rk_time", time() + 180 - query("level"));
                set("rk_time", time() + 3);
                remotekill_enemlist();
        }
        return ::heart_beat();
}

int receive_damage(string type, int n, object who) 
{ 
        int lv = query("level");
        object ob = query_last_damage_from();
        
          if ((ob && ob->is_worm()) || (query("chat_chance") && lv < 90)) return ::receive_damage(type, n, who);
        if (n >= query("max_qi")) {
                if (lv<80) n = query("max_qi") / 2;
                else n = query("max_qi") / 4;
        }
          if (lv<80) return ::receive_damage(type, n / 100 * (100 - lv), who);
        if (lv=99 || ((random(lv+1)>=70) && query("jzxg_time")<time())) {
                set("jzxg_time",time()+100-lv);
                if (query("jzxg_msgtime")<time()){
                        set("jzxg_msgtime",time());
                        message_vision(HIW "$N暗運" BLINK HIY "九轉玄功" NOR HIW "，堅若不動金剛，萬法不侵。\n" NOR, this_object());
                }
                  return ::receive_damage(type, 100-lv,who);
        }
          return ::receive_damage(type, n / 3, who);
} 
      
int receive_wound(string type, int n, object who) 
{ 
        int lv = query("level");
        object ob = query_last_damage_from();
        
        if ((ob && ob->is_worm()) || (query("chat_chance") && lv < 90)) return ::receive_wound(type, n, who);
        if (n >= query("max_qi")) {
                if (lv<80) n = query("max_qi") / 2;
                else n = query("max_qi") / 4;
        }
        if (lv<80) return ::receive_wound(type, n / 100 * (100 - lv), who);
        if (lv=99 || ((random(lv+1)>=70) && query("jzxg_time")<time())) {
                set("jzxg_time",time()+100-lv);
                if (query("jzxg_msgtime")<time()){
                        set("jzxg_msgtime",time());
                        message_vision(HIW "$N暗運" BLINK HIY "九轉玄功" NOR HIW "，堅若不動金剛，萬法不侵。\n" NOR, this_object());
                }
                return ::receive_wound(type, 100-lv, who);
        }
        return ::receive_wound(type, n / 3, who);
} 
      


void init()
{
        //string there;
        //there = base_name(environment());
        if (//(strsrch(there, "/u/redl/teleport/huaguo") != -1) &&
                query("short", environment())=="水簾洞" &&
                base_name(this_player()) != base_name(this_object())
        ) {
                if (query("env/invisible", this_player())) return;
                message_vision(append_color(NOR + CYN + "$N對$n怒喝道：何方妖怪敢擅闖我花果山？\n" + NOR, CYN), this_object(), this_player());
                this_object()->kill_ob(this_player());
        }
}

void ptdh(int lv)
{
        int i = 0;
        if (lv<=1) {
                if (!random(30)) {
                while (i++ < 9) { 
                        //DEBUG_CHANNEL("..."+(string)i+"\n" NOR);
                                if (random(i) == 0 ) { 
                                        lv += 1;
                } else 
                                        break; 
                        } 
                }
        }
        else {
                while (i++ < 9) { 
                        //DEBUG_CHANNEL("..."+(string)i+"\n" NOR);
                                if (random(i) == 0 ) { 
                                        lv += 1;
                } else 
                                        break; 
                        } 
        }
        if (lv>9) lv=9;
        if (lv>0) set("my_life", 9 + 10 * lv);
}

void create()
{
                int lv = 0, *t;
                set_name("猴王", ({ "hou wang", "hou", "wang", "monkey" }));
        set("race", "野獸");
        set("age", 23);
        set("long", "這是一隻身材碩壯的大馬猴，眼神中透露出一股霸\n"
                    "氣，看起來極不好惹。\n");
        set("rank_info/rude", "孽畜");
        set("rank_info/respect", "大猴子");
        set("combat_exp", 500000000);
        set("attitude", "heroism");
        set("str", 80);
        set("int", 10);
        set("con", 80);
        set("dex", 80);

        set("max_neili", 5000);
        set("neili", 5000);
        set("max_jing", 4000);
        set("jing", 4000);
        set("max_qi", 6000);
        set("qi", 6000);
        set("jingli", 3000);
        set("max_jingli", 3000);
        set("jiali", 300+random(300));

        set_skill("cuff", 250);
        set_skill("mizong-houquan", 250);
        set_skill("parry", 250);
        set_skill("dodge", 250);
        set_skill("force", 250);
        set_skill("martial-cognize", 250);
        set_skill("force-cognize", 250);

        map_skill("cuff", "mizong-houquan");
        map_skill("parry", "mizong-houquan");
        prepare_skill("cuff", "mizong-houquan");

        set_temp("apply/attack",  200);
        set_temp("apply/defense", 300);
        set_temp("apply/damage",  300);
        set_temp("apply/unarmed_damage", 300);
        set_temp("apply/armor", 500);

        set("chat_chance", 10 + random(15));
        set("chat_msg", ({
                (: random_move :)
        }));

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "cuff.zhen" :),
        }));
        set("auto_perform", 1);
                set_heart_beat(1);
                set("rnd_moved", 1);
        setup();

        if (!random(3))
                set_temp("handing", carry_object("/d/emei/obj/pantao"));
        t = TIME_D->analyse_time(TIME_D->query_real_time());
        if (random(3) && t[1]>=19 && t[1]<=22) {
                set("doubi", 1);
                //lv = 1;
                lv = 2;
                if (t[2]==5) lv += 1;
                if (t[2]==6) lv += 2;
                if (t[2]==0) lv += 3;
        }
                ptdh(lv);
}

int accept_object(object me, object ob)
{
        if( !query("food_supply", ob) )
        {
                message_vision(CYN "$N" CYN "擺了擺手，吱吱吱吱一陣"
                               "亂叫。\n" NOR, this_object());
                return 0;
        }

        if( query("food") >= max_food_capacity()-query("food_supply", ob) )
        {
                message_vision(CYN "$N" CYN "伸長脖子嗅嗅，擺了擺手"
                               "，打了一個飽嗝。\n" NOR, this_object());

                if (present("pan tao", this_object()))
                {
                        message_vision(CYN "\n$N" CYN "撓了撓頭，從身後摸出"
                                       "個水靈靈的大蟠桃，又嗅了嗅。\n" NOR,
                                       this_object());

                        command("give pan tao to "+query("id", me));
                        command("hehe");
                }
                return 0;
        }

        message_vision(CYN "$N" CYN "一把抓過$n" NOR + CYN "，使勁嗅了嗅。\n"
                       NOR, this_object(), ob);

        ob->move(this_object());

        command("eat "+query("id", ob));
        command("stuff");
        command("shzi");
        return 1;
}

int accept_fight(object ob)
{
        message_vision(CYN "$N" CYN "朝著$n" CYN "吱吱吱吱一陣亂叫。"
                       "\n" NOR, this_object(), ob);
        return 0;
}

void fight_ob(object ob)
{
        if (is_fighting(ob))
                return;

        message_vision(HIW "$N" HIW "仰天一聲長哮，朝$n" HIW "猛撲了"
                       "上去。\n" NOR, this_object(), ob);

        ::fight_ob(ob);
        if( !is_killing(query("id", ob)) )
                kill_ob(ob);
}

int accept_kill(object ob)
{
        return 1;
}

int accept_hit(object ob)
{
        return 1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        ob->receive_wound("qi", 80 + random(50), me);
        addn_temp("can_learn/houwang", 1, ob);
        return random(2) ? HIY "陡然間$N" HIY "招式一變，騰空躍起，雙"
                           "爪竟似幻作兩道金光，宛若星劃長空，颼的抓向"
                           "$n" HIY "而去。\n" NOR:

                           HIY "$N" HIY "驀地裡一聲清嘯，雙拳迴圈斜揮"
                           "而出，招式煞為精奇。$n" HIY "登時只覺眼花"
                           "繚亂，難以招架。\n" NOR;
}

void die(object killer)
{
//      string prop,name;
//      mapping data;
        object *obs, ob/*, where*/;
                object *enemies/*, *enemies2*/, enemy/*, enemy2*/;
                int num;

        if( random(100)>=(70 - query("level")) && 
                objectp(ob = previous_object(0)) && sscanf(base_name(ob), "/kungfu/skill/%*s") )
        {
                full_self();
                return;
        }

        if( !objectp(killer) ) killer = this_object()->query_last_damage_from();
        if( !objectp(killer) ) killer = query_temp("last_damage_from");

        if (query("my_life", this_object()) > 0)
        {
                addn("my_life", -1, this_object());
                if (objectp(killer) &&
                        !killer->is_busy() &&
                        !random(4)
                ) killer->start_busy(2 + random(2));
                else {
                        if ( objectp(killer) && !killer->is_busy() ) 
                                killer->start_busy(1);
                        this_object()->start_busy(1);
                }
                        
            level_up();
            return;
        }

        if (query("level", this_object())){
                obs = filter_array(all_inventory(this_object()), (: query("id", $1) == "pan tao" :));
                if (obs && arrayp(obs) && sizeof(obs)) {
                        num = sizeof(obs);
                        CHANNEL_D->channel_broadcast("news", NOR YEL "聽說"+query("short", environment())+NOR YEL"的"+query("name")+"死後留下"+ HIY + chinese_number(num)+ NOR +
                                 YEL + "個" + HIR "蟠桃" + NOR YEL  + "。\n" NOR);
                }
                if (num>0) enemies = filter_array(query_enemy(),
                           (: playerp($1) &&
                           living($1)
                           :));
        if (enemies && arrayp(enemies) && sizeof(enemies)>0) {
            while(num--){
                enemy = enemies[random(sizeof(enemies))];
                    message_vision(NOR + CYN + "$N" + NOR + CYN + "見"+query("name")+"倒地，一擁而上哄搶到一個" + HIR + "蟠桃" + NOR + CYN + "。\n" + NOR, enemy);
                obs[num]->move(enemy, 1);
            }
        }
        }
    return ::die(killer);
}

void unconcious()
{
     object ob,me = this_object();
     if(!objectp(ob)) ob = me->query_last_damage_from();
     if(!objectp(ob)) ob = query_temp("last_damage_from",me);
         if( objectp(ob) && userp(ob) && ob->query_skill("mizong-houquan",1) >999 
         && random(ob->query_int())>500 && !random(10) 
         && !query("can_perform/mizong-houquan/zhen",ob) )
         {
         tell_object(ob,HIR"\n突然間，你心靈福至，暮然領悟了迷蹤猴拳的絕招"HIC"「震字訣」"HIR"！\n");
         set("can_perform/mizong-houquan/zhen",1,ob);
         }
     if (objectp(ob)
           && ! ob->query_skill("mizong-houquan", 1)
            && query_temp("can_learn/houwang", ob)>30
            && query("combat_exp",ob)>100000
           && ob->query_skill("cuff", 1) > 100
           && ob->query_skill("force", 1) > 100
            && query("max_neili", ob)>1200
            && query("int", ob)>26
            && query("dex", ob)>24
           && random(50) == 1
           && userp(ob))
        {
                tell_object(ob, HIW "\n你通過和猴王格鬥，突然間靈光一"
                                "閃，領悟出了猴拳的真詣所在。\n\n" NOR +
                                HIC "恭喜你練成了「迷蹤猴拳」。\n" NOR);
      message("channel:rumor",MAG"【謠言】某人：聽說"+query("name", ob)+NOR+MAG"和猴子大戰三百回合，學會了「迷蹤猴拳」。\n"NOR,users()); 
                ob->set_skill("mizong-houquan", 49);
                ob->improve_skill("mizong-houquan", 1500000);
                ob->improve_skill("martial-cognize", 1500000);
        }
     die(ob);
}
