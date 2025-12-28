// This program is a part of NT MudLIB
// redl 2014
// 辛辰子

#include <ansi.h>

inherit BOSS;

void del_busy();
int hand_throw();

int accept_object(object me, object obj)
{
        int amount;
        object sword, ob = this_object();

                if (ob->is_fighting() || ob->is_busy()) {
                        tell_object(me,CYN + query("name") + NOR + CYN + "慢悠悠地對你說道：沒見我正在忙嗎？\n"+ NOR); 
                        return 0;
                }
        
        return "/d/wudu/npc/jincangu.c"->is_complete_request(ob, me, obj);
        
/*      switch (query("id", obj))
        {                       
         case "no name":
                if (base_name(obj) == "/clone/goods/noname") {
                        if (query("give_sword")) {
                                tell_object(me,CYN + query("name") + NOR + CYN + "慢悠悠地對你說道：我已經收到有緣人的贈予了。\n"+ NOR); 
                                return 0;
                        }
                        sword = query("my_sword");
                        if (!sword) {
                                tell_object(me,CYN + query("name") + NOR + CYN + "慢悠悠地對你說道：我給不了你什麼。\n"+ NOR); 
                                return 0;
                        }
                        sword->unequip();
                        if (sword->move(me)) {
                                set("give_sword", 1);
                                set("owner_ob", me, sword);
                                message_vision(CYN + query("name") + NOR + CYN + "接過$N的無名之物，遞還了一個劍匣子作為答謝。\n"+ NOR, me); 
                                return 1;
                        }
                        tell_object(me,CYN + query("name") + NOR + CYN + "慢悠悠地對你說道：我給不了你什麼。\n"+ NOR); 
                        return 0;
                } else {
                        tell_object(me,CYN + query("name") + NOR + CYN + "慢悠悠地對你說道：這個東西是高仿的嗎？\n"+ NOR); 
                        return 0;
                }
                         default:
                return 0;
        }*/

        
        
}

void create()
{
        set_name(CYN "辛辰子" NOR, ({ "xin chenzi", "xin", "chenzi" }) );
        set("title", HIG "百蠻山" HIC "弟子" NOR);
        set("nickname", HIB "獨臂韋護" NOR);
        set("long", HIR "這是百蠻山的二代弟子，奉命蒐集夜明砂，替綠袍餵養百毒金蠶蠱。\n" NOR);

        set("gender", "男性");
        set("age", 39);
        set("str", 1000);
        set("int", 500);
        set("con", 500);
        set("dex", 500);
        set("shen", -5000000);
        set_temp("apply/attack", 1200000);
        set_temp("apply/unarmed_damage", 150000);
        set_temp("apply/damage", 150000);
        set_temp("apply/armor", 50000);

        set("max_qi", 35000000000);
        set("eff_qi", 35000000000);
        set("qi", 35000000000);
        set("max_jing", 18000000000);
        set("jing", 18000000000);
        set("eff_jing", 18000000000);
        set("max_jingli", 500000000);
        set("jingli", 500000000);
        set("max_neili", 2500000000);
        set("neili", 2500000000);
        set("jiali", 10000);
        set("combat_exp", 5000000000);
        set("level", 110 + random(30));

        set_skill("unarmed", 22000);
        set_skill("finger", 22000);
        set_skill("claw", 22000);
        set_skill("strike", 22000);
        set_skill("hand", 22000);
        set_skill("cuff", 22000);
        set_skill("parry", 22000);
        set_skill("dodge", 22000);
        set_skill("force", 22000);
        set_skill("sword", 22000);
        set_skill("blade", 22000);
        set_skill("throwing", 22000);
        set_skill("zuoyou-hubo", 1000);
        set_skill("poison", 5000);
        
        set_skill("xuedao-daofa", 13300 + random(7888));
        set_skill("shexing-lifan", 13300 + random(7888));
        set_skill("chousui-zhang", 13300 + random(7888));
        set_skill("sanyin-zhua", 13300 + random(7888));
        set_skill("huagong-dafa", 13300 + random(7888));
        set_skill("freezing-force", 13300 + random(7888));
        set_skill("xingxiu-qishu", 13300 + random(7888));
        set_skill("feixing-shu", 13300 + random(7888));
        set_skill("martial-cognize", 13300 + random(5000));
        set_skill("bingchan-gong", 5000);
        set_skill("count", 6000 + random(3000));
        set_skill("literate", 5000);
        set_skill("huajia-su", 1500);
        set_skill("jingluo-xue", 5000);
        set_skill("qimen-wuxing", 1000);

        set("no_nuoyi", 1); // 不被挪移影響
        set("yuanshen", 1); //無招

        map_skill("parry", "chousui-zhang");
        map_skill("force", "freezing-force");
        map_skill("dodge", "shexing-lifan");
        map_skill("strike", "chousui-zhang");
        map_skill("claw", "sanyin-zhua");
        map_skill("poison", "xingxiu-qishu");
        map_skill("throwing", "feixing-shu");
        map_skill("blade", "xuedao-daofa");

        prepare_skill("strike", "chousui-zhang");
        prepare_skill("claw", "sanyin-zhua");

//        set("can_perform/qiankun-danuoyi/yi", 1);

         set("chat_chance", random(7) + 3);
         set("chat_msg", ({
                (: command("say 此回和洪兄借得好刀，回山瞅個機會一定要讓老怪好看。") :),
                (: command("say 一千夜明砂，我要收集到何時才夠呢。") :),
                (: command("say 洪兄給我這法寶干係太大，不知道他會不會受到師傅的嚴罰。") :),
                (: command("say 聽說這刀，嗜血越多越厲害...") :),
                (: command("say 多帶點器官回去，就能避開老怪的殘害了吧...") :),
         }));

        set("my_life", 1); // 當氣血低於10%的時候補滿一次，設置該參數為0

        set("auto_perform", 1);
        //set("end_time", 60);  // 必須戰鬥不少於60秒後死亡
        set("rewards", ([
                "exp"   : 500000,
                "pot"   : 250000,
                "mar"   : 100000,
                "weiwang" : 20000,
                "score" : 20000,
                "gold"  : 10000,
        ]));

/*        set("drops", ([
                "FI&/clone/medal/diamond_xunzhang"       : 1,
                "FI&/clone/medal/yongshi_xunzhang"      : 10,
                "FI&/clone/fam/max/longjia"       : 100,
        ]));*/

        set_temp("apply/reduce_damage", 72);
        set_temp("apply/reduce_busy", 35);
        set_temp("apply/add_busy", 10);
        set_temp("apply/add_poison", 70);

/*        set("inquiry", ([
                "除魔" : (: get_helpkill :),
        ]));*/

                set("n_flee", 7200);
        setup();

                set("hand_throwing", "/clone/weapon/tielianzi");
        carry_object("/kungfu/class/quanzhen/obj/greyrobe")->wear();
        set("my_sword", new(__DIR__"obj/thxdao"));
        set("owner_ob", this_object(), query("my_sword"));
                set_temp("kill_num", 500000, query("my_sword"));
        set("give_sword", 0);
        hand_throw();

}

int hand_throw()
{
        object ob, me = this_object();
        
        if (query_temp("handing")) return 1;
        if (!query("hand_throwing")) return 1;

        ob = new(query("hand_throwing"));
        if( ob->query_amount() ) {
                ob->set_amount(999);
        }
        
        ob->move(me, 1);
        command("hand " + query("id", ob));
        return 1;
}

void heart_beat()
{
                object sword, me = this_object();
        if( query("n_flee") < 1 ){
                        message_vision(CYN + query("name") + NOR + CYN + "仰天長嘆：看來此番峨眉氣數未盡，罷了，罷了...\n"+ NOR + 
                                                                                query("name") + NOR + YEL + "說完掐了個口訣一頓足，乘著滾滾黑煙破空而去。\n" + NOR, me); 
                                destruct(this_object());                                                                            
                return;
        }      
        addn("n_flee", -1);
        if (random(3) == 1)
        {
            delete_temp("no_perform");
            delete_temp("no_exert");
                    hand_throw();
                    /*if (this_object()->is_fighting() && !random(100)) {
                        command("unwield huaxue dao");
                        command("drop huaxue dao");
                        command("perform finger.zhuan");//call die()絕殺一次
                    }*/
        }
                if (!this_object()->is_fighting() && !random(10)) {
                        me->stop_busy();
                        command("halt");
                        me->stop_busy();
            command("yun powerup");
            me->stop_busy();
                        full_self(); // 補滿氣血
                }
        return ::heart_beat();
}

void del_busy()
{
        object me = this_object();
        if (random(8)) return;
        if (me->is_busy()) me->interrupt_busy(me, 1000);
        if (me->is_busy()) me->interrupt_me(me);
        if (me->is_busy()) me->stop_busy();
        if (me->is_busy()) me->interrupt_busy(me);
}

int accept_hit(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

int accept_fight(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

int accept_kill(object me)
{
        this_object()->kill_ob(me);
        return 1;
}

void new_life()
{
        full_self(); // 補滿氣血
                del_busy();
        delete_temp("no_perform");
        delete_temp("no_exert");

        addn_temp("apply/attack", query_temp("apply/attack") * 2);
        addn_temp("apply/unarmed_damage", query_temp("apply/unarmed_damage") / 2);
        addn_temp("apply/damage", query_temp("apply/damage") / 2);
        addn_temp("apply/armor", query_temp("apply/armor") * 2);

        addn("my_life", -1);
        message_vision(HIG "\n$N" HIG "暴喝一聲燃起天師符，瞬間神光四湛！\n\n" NOR, this_object());
        return;
}

int receive_damage(string type, int damage, object who)
{
        object *ppl;

        if( !who ) who = this_object()->query_last_damage_from();
        if( !who ) return;
        ppl = query_temp("damage_from");
        if( !arrayp(ppl) || !sizeof(ppl) ) ppl = ({});
        if( userp(who) && member_array(who, ppl) == -1 )
        {
                ppl += ({ who });
                set_temp("damage_from", ppl);
        }

        if (query("my_life") && query("qi") < query("max_qi") / 10)
        {
                new_life(); // 重生一次
                return 0;
        }

        return ::receive_damage(type, damage, who);
}

void die(object killer)
{
        string prop, name;
        mapping data;
        object sword, ob, where;
/*        string *apply = ({ "reduce_busy", "avoid_busy", "def_damage", "avoid_weak",
                "add_locked", "reduce_damage", "add_busy", "add_weak", "avoid_locked",
                "add_damage", "add_skill" });*/

        if( objectp(ob = previous_object(0)) && sscanf(base_name(ob), "/kungfu/skill/%*s") )
        {
                full_self();
                return;
        }

        if( !objectp(killer) ) killer = this_object()->query_last_damage_from();
        if( !objectp(killer) ) killer = query_temp("last_damage_from");

        // 如果還未重生，則重生一次
        if (query("my_life"))
        {
                new_life();
                return;
        }

        if( time() < query_temp("end_time") ) // 時間沒有到，死亡不了
        {
                addn("jing", query("max_jing") / 10);
                if( query("jing") > query("max_jing") ) set("jing", query("max_jing"));
                addn("eff_jing", query("max_jing") / 10);
                if( query("eff_jing") > query("max_jing") ) set("eff_jing", query("max_jing"));
                addn("qi", query("max_qi") / 10);
                if( query("qi") > query("max_qi") ) set("qi", query("max_qi"));
                addn("eff_qi", query("max_qi") / 10);
                if( query("eff_qi") > query("max_qi") ) set("eff_qi", query("max_qi"));
                //message_vision(HIR "\n$N" HIR "大喝一聲，運用秘法，氣血有所回升！\n\n" NOR, this_object());
                return;
        }

/*              if (new(__DIR__"obj/tnmjian")->move(killer, 1)) {
                message_vision(HIR "叮~~一聲，從$N" HIR "身上掉出一個劍匣子，$n" HIR
                                   "趕緊揀起來揣到懷裡。\n" NOR, this_object(), killer);
                        set("jldong/killshu_time", time() , killer);
        }*/
        message_vision(CYN + query("name") + NOR + CYN + "捂住嘴角的" + NOR + HIR + "鮮血" + NOR + CYN + "道：看來此番峨眉氣數未盡，罷了，罷了...\n"+ NOR + 
                        query("name") + NOR + YEL + "說完掐了個口訣一頓足，乘著滾滾黑煙破空而去。\n" + NOR, this_object()); 

                        sword = query("my_sword");
                        if (killer && sword && !query("give_sword")) {
                                set("give_sword", 1);
                                set("owner_ob", killer, sword);
                                delete_temp("kill_num", sword);
                                tell_object(killer, NOR + "你發現空中落下一個漆黑刀鞘，趕緊撿了起來..\n"+ NOR); 
                                sword->reset_wield();
                                set_temp("xue/xin/killed", 1, killer);
                        }

                destruct(this_object());                                                                                
                return;
        //return ::die(killer);
}

varargs void unconcious(object defeater)
{
        object ob;

        //if( query("end_boss") || query("fight_boss") )
        if( objectp(ob = previous_object(0)) && sscanf(base_name(ob), "/kungfu/skill/%*s") ) {
                full_self();
                return;
        }
        die(defeater);
        return;
}

/*// 不會被busy
varargs void start_busy(mixed new_busy, mixed new_interrupt)
{
        return;
}*/
