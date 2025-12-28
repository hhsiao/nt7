inherit BOSS;
#include <ansi.h>

void check_weapon();

void create()
{
        object staff;
        
        set_name("蚩尤巨像", ({ "chi you", "chiyou" }) );
        set("race", "人類");
        set("gender", "男性");
        set("age", 10000);
        set("long", "蚩尤，與黃帝涿鹿中原的一代大神，鬢如劍戟，頭有利角，銅頭鐵額，誅殺 
無道，乃古往今來睥睨天下之第一兇魔！他的頭頂，有一根放射出萬道金華
的[37m法杖[32m沒頂而插\n");
        set("title", "不世戰神");
        set("nickname", HIR"萬古兇魔"NOR);
        
        set("NO_KILL","你無法攻擊一具石像。\n"); 
        set("attitude", "peaceful");

        set("per", 21);
        set("str", 300);
        set("int", 300);
        set("con", 300);
        set("dex", 300);

        set("qi", 20000000000);
        set("max_qi", 20000000000);
        set("jing", 10000000000);
        set("max_jing", 10000000000);
        set("neili", 130000000000);
        set("max_neili", 130000000000);
        set("jiali", 30000);

        set("combat_exp", 15000000000);
        set("score", 0);
        set_skill("force", 4800);
        set_skill("moshen-xinfa", 4800);
        set_skill("chiyou-kuangzhanjue", 4800);
        set_skill("dodge", 4800);
        set_skill("moshen-bufa", 4800);
        set_skill("jiutian-xiaoyaobu", 4800);
        set_skill("strike", 4800);
        set_skill("moshen-zhangfa", 4800);
        set_skill("cuff", 4800);
        set_skill("moshen-quanfa", 4800);
        set_skill("sword", 4800);
        set_skill("moshen-jianfa", 4800);
        set_skill("liuxing-jianfa", 4800);
        set_skill("blade", 4800);
        set_skill("moshen-daofa", 4800);
        set_skill("moon-blade", 4800);
        set_skill("parry", 4800);
        set_skill("literate", 4800);
        set_skill("medical", 4800);
        set_skill("mojiao-medical", 4800);
        set_skill("motun-tianxia", 4800);
        set_skill("martial-cognize", 4800);

        map_skill("force", "chiyou-kuangzhanjue");
        map_skill("dodge", "jiutian-xiaoyaobu");
        map_skill("strike", "moshen-zhangfa");
        map_skill("cuff", "moshen-quanfa");
        map_skill("sword", "liuxing-jianfa");
        map_skill("blade", "moon-blade");
        map_skill("parry", "moon-blade");

        prepare_skill("strike", "moshen-zhangfa");

        set("no_nuoyi", 1); // 不被挪移影響
        
        set("my_life", 1); // 當氣血低於10%的時候補滿一次，設置該參數為0
        set("staff", 1);
        
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.ting" :),
                (: perform_action, "blade.yue" :),
                (: exert_function, "recover" :),
        }) );
        
        set("rewards", ([
                "exp"   : 800000,
                "pot"   : 400000,
                "mar"   : 80000,
                "weiwang" : 10000,
                "score" : 10000,
                "gold"  : 3000,
        ]));

        set("drops", ([
                "FI&/clone/tessera/rune29"      : 10,
                "FI&/clone/tessera/rune30"      : 1,
                "FI&/clone/goods/luck_ring"      : 1,
                "FI&/clone/goods/luck_charm"      : 1,
                "FI&/clone/goods/luck_neck"      : 1,
                "FI&/clone/tongren/tongren"+(1+random(2)) : 500,
        ]));
        
        set_temp("apply/attack", 1000000);
        set_temp("apply/unarmed_damage", 100000);
        set_temp("apply/damage", 100000);
        set_temp("apply/armor", 60000);

        set_temp("apply/reduce_damage", 80);
        set_temp("apply/avoid_busy", 66);
        set_temp("apply/reduce_busy", 66);
        set_temp("apply/add_busy", 25);
        set_temp("apply/reduce_poison", 80);
                                
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/kungfu/class/mojiao/obj/blade")->wield();
}

void init() 
{
        if (query("staff"))
                add_action("do_pull", "pull");
        if (interactive(this_player()) && !query("NO_KILL")){
                kill_ob(this_player()); 
                this_player()->kill_ob(this_object());
        }
}

string staff()
{
        object me;
        me = this_player();
        if(query("staff")){
                tell_object(me, YEL"\n
一柄由萬載菩提木製成的法杖，一大半已深深插入蚩尤巨像頭頂，但露出的一部分
依舊光華奪目，不知道是否能拔出來（pull)；據傳上古時黃帝斬殺蚩尤巨兇後，
唯恐其亡魂不散，特向佛祖借來這萬年菩提杖插入蚩尤石像，以鎮住這不世之兇，
萬世不得翻身。\n\n"NOR);
        } else {
                tell_object(me, "大神蚩尤像頭頂的法杖已然不見，只剩一個空洞。\n");
        }
        return "";
}

int do_pull(string arg)
{
        object me, staff;
        int damage;
        me = this_player();
        
        if(!arg || (arg != "staff" && arg != "法杖")) {
                return notify_fail("你要拔什麼？\n");
        }
        if(!query("staff")) {
                return notify_fail("已經沒有法杖了。\n");
        }
        if(query("qi",me) < 100) {
                return notify_fail("你沒有足夠的氣血。\n");
        }
        if(query("jiali",me) > 80 && me->query_str() > 30 ) {
                message_vision("$N雙手緊緊握住菩提法杖，牙關一咬，虎口鮮血迸射，怒喝一聲：起！！\n", me);
                message_vision(HIY"\n菩提法杖突然放出萬道金華，七色彩暈，山搖地動之間，法杖應聲而起，沖天而出！\n"NOR,
                                me);  
        set("long", "蚩尤，與黃帝涿鹿中原的一代大神，鬢如劍戟，頭有利角，銅頭鐵額，誅殺 
無道，乃古往今來睥睨天下之第一兇魔！\n");
                set("staff", 0);
                me->start_busy(3);
                call_out("stone_fall", 3, me);
        } else {
                message_vision("$N雙手緊緊握住菩提法杖，牙關一咬，虎口鮮血迸射，怒喝一聲：起！！\n", me);
                message_vision("菩提法杖紋絲不動。\n", me);
                me->start_busy(3);
                damage = query("qi",me) / 5;
                me->receive_damage("qi", damage);
        }
        return 1;
}

void stone_fall(object me)
{
        object *all, *inv, room, obj;
        int i;
        
        all = all_inventory(environment(this_object()));
        
        message_vision("\n突然之間蚩尤秘窟有如天崩地裂般，濃雲翻滾，電閃雷鳴，山石又如疾風暴雨般\n", me);        
        message_vision("漫天砸下！\n", me); 
        message_vision("\n$N神色大變，奮起全力在亂石風暴中苦苦尋求一線生機。\n", me);
        
        inv = filter_array(all, (: interactive($1):));
        for(i=0; i<sizeof(inv); i++) {
                message_vision(HIY"$N被這突如其來的變化驚的目瞪口呆，只見無數巨石狠狠地砸了過來，\n"NOR, inv[i]);
                message_vision(HIY"當真是擋無可擋躲無可躲。\n"NOR, inv[i]);
                if(inv[i]->query_skill("dodge",1)>=1500 && inv[i]->query_skill("parry",1)>=1500){
                        message_vision(HIG"\n在這間不容髮的情況下$N躲過了巨石的攻擊。\n"NOR, inv[i]);
                } else {
                        tell_object(inv[i], "你左擋右躲向前奔跑期望躲過巨石的襲擊。\n");
                        me->start_busy(3);
                        
                        message_vision(RED"\n$N一個躲閃不及，無數巨石狠狠地砸了過來。。。\n"NOR, inv[i]);          
                        inv[i]->unconcious(me);
                }
        }
        
        remove_call_out("chiyou");
        call_out("chiyou", 3, me);
        
}

void chiyou(object ob)
{
        object *all, *inv;
        int i;
        
        if(!interactive(ob) && environment(ob) != this_object()){
                set("staff",1);
                return;
        }
        message_vision(HIB"\n漫天亂石中，狂風乍起，天色變得一片猙獰，彷彿無數厲鬼野獸在咆哮怒吼！\n"NOR, ob);
        message_vision(HIR"\n鮮紅如血般的大火熊熊燃起，一片火海中升起一個高達百尺，有如天神般的巨漢！\n"NOR,ob); 
        message_vision(HIR"遠處，近處，空氣中每一處地方無數的兇靈邪獸齊聲膜拜，狂呼！！\n\n"NOR, ob);
        message_vision(HIY"              －－不－世－戰－神－－蚩－尤－重－生－－  \n\n"NOR, ob);
        
        delete("NO_KILL");      
        set("name","蚩尤");
        
        all = all_inventory(environment(this_object()));
        inv = filter_array(all, (: interactive($1):));
        for(i=0; i<sizeof(inv); i++) {
                kill_ob(inv[i]);
                inv[i]->kill_ob(this_object());
                }
}

void heart_beat()
{
        // 解除不能perform yun的限制
        if (random(3) == 1)
        {
                delete_temp("no_perform");
                delete_temp("no_exert");
        }

        if (random(3) == 1)check_weapon();

        return ::heart_beat();
}

// 檢查武器
void check_weapon()
{
        object me, ob;

        me = this_object();

        // 同時補充內力
        set("neili", query("max_neili"));

        if (me->is_busy()) me->stop_busy();

        if (! query_temp("weapon"))
        {
                if( !objectp(ob = present("springrain blade", environment(me))) )
                ob = new("/kungfu/class/mojiao/obj/blade.c");
                ob->move(me);
                ob->wield();
        }

        if (random(5) >= 0) // 百分百
        {
                delete_temp("no_perform");
                delete_temp("no_exert");

                addn_temp("apply/damage", 50000);
                if (random(5) == 1)
                        command("perform balde.ting");
                else
                        command("perform blade.yue");
                addn_temp("apply/damage", -50000);

                if (random(2))
                {
                        delete_temp("eff/jiuyin-shengong/xin");
                }
        }

        if (random(10) == 1)
        {
                me->clear_condition();
        }

        // 很小几率恢復氣血
        if (random(1000) == 1)
        {
                if (query("eff_qi") < query("max_qi") / 3) addn("eff_qi", query("max_qi") / 5);
                if (query("qi") < query("max_qi") / 3) addn("qi", query("max_qi") / 5);
        }

        if (! me->is_fighting() || random(5) == 1)
        {
                command("yun powerup");
        }

        return;
}

int accept_hit(object me)
{
        if( query("NO_KILL") ) return 0;
        this_object()->kill_ob(me);
        return 1;
}

int accept_fight(object me)
{
        if( query("NO_KILL") ) return 0;
        this_object()->kill_ob(me);
        return 1;
}

int accept_kill(object me)
{
        if( query("NO_KILL") ) return 0;
        this_object()->kill_ob(me);
        return 1;
}

int accept_ansuan(object me) 
{     
        if( query("NO_KILL") ) return 0;
        return notify_fail("那人警惕性好高，你難以下手。\n"); 
}

int accept_touxi(object who) 
{
        if( query("NO_KILL") ) return 0;
        return notify_fail("那人警惕性好高，你難以下手。\n"); 
}
        
void new_life()
{
        full_self(); // 補滿氣血

        delete_temp("no_perform");
        delete_temp("no_exert");

        set_temp("apply/attack", 1200000);
        set_temp("apply/unarmed_damage", 150000);
        set_temp("apply/damage", 150000);
        set_temp("apply/armor", 100000);

        delete("my_life");

        message_vision(HIG "\n$N" HIG "大喝一聲，目光頓時充滿殺意！\n\n" NOR, this_object());

        return;
}

void die(object killer)
{
        string prop, name;
        mapping data;
        object ob, where;
        string *apply = ({ "reduce_busy", "avoid_busy", "def_damage", "avoid_weak",
                "add_locked", "reduce_damage", "add_busy", "add_weak", "avoid_locked",
                "add_damage", "add_skill" });

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

        message_vision(HIR"\n$N嘶叫道：“可惡的。。。。我會再回來的。”"NOR, this_object());
        message_vision(HIR"$N那龐大身軀突然化為一股濃煙消失不見了。\n"NOR, this_object());

        return ::die(killer);
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
