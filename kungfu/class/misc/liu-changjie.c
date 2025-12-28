// This program is a part of NT MudLIB

#include <ansi.h>
#include <command.h>

// 經驗過高後無任何獎勵
#define MAX_EXP              50000000

void smart_fight();
void random_move();
void death_msg();

inherit BOSS;

void create()
{
        set_name("柳長街", ({ "liu changjie", "changjie" }) );
        set("long", "柳葉飄飄，任我飛舞，長街漫漫，任我逍遙。\n");
        set("gender", "男性");
        set("age", 30);
        set("title",HIY"太虛任遨遊"NOR);
        set("attitude", "friendly");
        set("str", 35);
        set("int", 30);
        set("con", 30);
        set("dex", 46);
        set("per", 20);
        set("shen_type", 0);

        set("qi", 12000000);
        set("max_qi", 12000000);

        set("jing", 4000000);
        set("max_jing", 4000000);
        set("jingli", 4000000);
        set("max_jingli", 4000000);

        set("neili", 35000);
        set("max_neili", 35000);
        set("jiali", 1200);
        set("combat_exp", 20000000);

        set("level", 30);

        set_skill("force", 1000);
        set_skill("pixie-jian", 800);
        set_skill("surge-force", 800);
        set_skill("six-finger", 800);
        set_skill("sword", 800);
        set_skill("finger", 800);
        set_skill("whip", 800);
        set_skill("dodge", 800);
        set_skill("parry", 800);
        set_skill("unarmed", 800);
        set_skill("strike", 800);
        set_skill("zuoyou-hubo", 500);
        set_skill("literate", 1000);
        set_skill("throwing", 800);
        set_skill("jueqing-quyu", 500);
        set_skill("jingluo-xue", 500);
        set_skill("martial-cognize", 700);

        map_skill("force", "surge-force");
        map_skill("sword", "pixie-jian");
        map_skill("dodge", "pixie-jian");
        map_skill("parry", "pixie-jian");
        map_skill("unarmed", "pixie-jian");
        map_skill("finger", "six-finger");

        prepare_skill("finger", "liumai-shenjian");

        set_temp("apply/attack",500);
        set_temp("apply/defense", 500);
        set_temp("apply/damage", 4000);
        set_temp("apply/unarmed_damage", 4000);
        set_temp("apply/armor", 4000);

        set("auto_perform", 1); // 自動出絕招
        //set("death_msg", (: death_msg :));

/*
        set("chat_chance", 30);
        set("chat_msg", ({ (: random_move :) }));
*/
        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
               (: smart_fight() :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                (: perform_action, "finger.tian twice" :),
        }) );

        set("rewards", ([
                "exp"   : 100000,
                "pot"   : 50000,
                "mar"   : 10000,
                "score" : 300,
                "gold"  : 5,
        ]));

        set("drops", ([
                "RA&RANDOM20"    :       100,   // 低級普通裝備
                "RA&RANDOM30"    :       40,    // 低級普通裝備
                "FI&/adm/npc/obj/ganjiang-symbol" :   20,
                "FI&/clone/goods/sun"    :   20,
                "FI&/clone/goods/moon"   :   20,
                "FI&/clone/tongren/tongren1"  :   2,
                "FI&/clone/tessera/rune09"  :   5,
                "FI&/clone/tessera/rune08"  :   10,
                "FI&/clone/misc/baoxiang" : 100,
        ]));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/baipao")->wear();
        set_temp("born_time", time());
        //if (clonep()) keep_heart_beat();
}

int accept_fight(object ob)
{
        kill_ob(ob);
        return -1;
}

int accept_kill(object ob)
{
        return 1;
}

int accept_hit(object ob)
{
        kill_ob(ob);
        return -1;
}

mixed hit_ob(object me, object ob, int damage_bouns)
{
        ob->start_busy(5 + random(6));
        //me->receive_wound("qi", 500 + random(600), ob);
        return HIY "$N" HIY "怒喝一聲，奮力反抗，竟逼得$n" HIY "手忙腳亂。\n" NOR;
}

void heart_beat()
{
        if (query("neili") < 1 && random(10) == 1)
                set("neili", query("max_neili"));

        return ::heart_beat();
}

void random_move()
{
        object env;

        if (time() - query_temp("born_time") > 1800)
        {
                env = environment(this_object());
                message_vision("$N急急忙忙的走了。\n", this_object());

                CHANNEL_D->channel_broadcast("news", HIG "聽說" + HIW + env->short() + "(" + LOOK_CMD->locate(base_name(env)) + ")" HIG "一帶出現的" +
                        HIR + this_object()->short() + HIR "消失了。\n" NOR);

                destruct(this_object());
                return;
        }
        //::random_move();
}

void death_msg()
{
        if (random(2) == 1)
        {
                command("chat* grin");
                command("chat 天地間任我逍遙，後會無期...！");
                CHANNEL_D->do_channel(this_object(), "rumor", "聽說" + name() + HIM "戰鬥中負傷後，奪路而逃。" NOR);
        }
        else
        {
                message_vision(HIG "猛然間，$N " HIG " 向後一跳，隨手仍出一顆黑色小丸，頓時騰起一片煙霧 ...\n" NOR,
                               this_object());
                command("chat 這是絕對不可能的，這次是個意外！！");
                CHANNEL_D->do_channel(this_object(), "rumor", "聽說" + name() + HIM "戰鬥中負傷後，奪路而逃。" NOR);
        }
}

void smart_fight()
{
        object ob,me;
        mapping buff;
        object target,*enemy,weapon;
        int f,i;
        string msg;
        
        enemy = query_enemy();
        me= this_object();

        weapon= query_temp("weapon", me);
        if( time() > query("last_time/busy")+ 6 )
        {
                message_vision(HIG"\n$N劍雨橫灑，佈滿整個戰場！\n"NOR,this_object());
                for( i=0;i<sizeof(enemy);i++ ) {
                        if( objectp(ob = enemy[i]) ) {
                                if( ob->query_busy() ) continue;
                                        message_vision(WHT"$n渾身劇震，諸般大穴似乎都被點中，完全動彈不得！\n"NOR,this_object(),ob);
                                        ob->start_busy(10);
                        }
                }
                set("last_time/busy",time());
        }

        if( query("last_time/huibi") + 3 < time() ) {
                set("last_time/huibi",time());
                
                target = select_opponent();

                add_temp("apply/attack",750);
                add_temp("apply/damage",4000);
                message_vision(BRED WHT"\n天外流星\n"NOR,this_object());

                msg = HIW "$N" HIW "手腕一陣疾抖，劍身微顫，劍作龍吟。剎那間劍芒陡漲，如天河倒瀉一般灑向$n" HIW "。" NOR;
                message_vision(BRED WHT+msg+NOR, this_object(), target);
                COMBAT_D->do_attack(me, target, weapon, 0);

                message_vision(  HIR "$n" HIR "頓時目瞪口呆，一個不慎，被$N"
                                           HIR "精妙的劍招刺中，鮮血飛濺！\n" NOR,me,target);
                target->receive_wound("qi",query("qi", target)/20,me);

                if (!random(2)) COMBAT_D->do_attack(me, target, weapon, 0);
                msg = HIY "$N" HIY "一聲清嘯，劍法忽變，手中長劍" + HIY "輕輕劃出，帶出一條無比絢麗的劍芒，遙指$n" HIY "而去。" NOR;
                message_vision(BRED WHT+msg+NOR, this_object(), target);
                COMBAT_D->do_attack(me, target, weapon, 0);

                if (!random(2)) COMBAT_D->do_attack(me, target, weapon, 0);
                add_temp("apply/damage",-4000);
                add_temp("apply/attack",-750);

        }
        return;
}
