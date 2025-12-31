// This program is a part of NT MudLIB

#include <ansi.h>
#include <combat.h>
#include <command.h>

void smart_fight();
void random_move();
void death_msg();

inherit BOSS;
inherit F_SSERVER;

void create() {
    set_name("成昆", ({ "cheng kun", "cheng" }) );
    set("long", sort_msg("謝遜之師，和前明教教主陽頂天夫人私通被發現，陽頂天因此走火而亡，夫人自殺，"
        "他深深不忿，仇恨無所宣洩，展開了龐大漫長的復仇計劃，通過謝遜來擾亂明教。後"
        "拜空見神僧為師，學得少林九陽功，又陰謀設局使空見被謝遜所殺。以高德大僧身份，"
        "結黨營私，圖謀不軌。暗地裡策動六大派圍攻光明頂...\n"));
    set("title", HIR"混元霹靂手"NOR);
    set("gender", "男性");
    set("class", "bonze");
    set("age", 55);
    set("attitude", "peaceful");
    set("str", 36);
    set("con", 33);
    set("dex", 30);
    set("int", 28);

    set("qi", 60000000);
    set("max_qi", 60000000);
    set("jing", 50000000);
    set("max_jing", 50000000);
    set("neili", 80000000);
    set("max_neili", 80000000);
    set("jiali", 30000);
    set("combat_exp", 2000000000);
    set("level", 70);
    set("score", 5000);
    set("jiali", 620);
    set("shen_type", -1);

    set_skill("finger", 1200);
    set_skill("force", 1200);
    set_skill("parry", 1200);
    set_skill("dodge", 1200);
    set_skill("shaolin-shenfa", 1200);
    set_skill("huanyin-zhi", 1200);
    set_skill("hunyuan-yiqi", 1200);
    set_skill("literate", 1200);
    set_skill("martial-cognize", 1200);

    map_skill("force", "hunyuan-yiqi");
    map_skill("parry", "poyang-jian");
    map_skill("finger", "huanyin-zhi");
    map_skill("dodge", "shaolin-shenfa");

    prepare_skill("finger", "huanyin-zhi");

    create_family("少林派", 36, "弟子");

    set("chat_chance", 30);
    set("chat_msg", ({
        (: random_move :),
        "師妹，自你去後，可知我是如何渡過的，不管有多苦，為你，我願成魔...\n "
    }));
    set("chat_chance_combat", 120);
    set("chat_msg_combat", ({
        (: perform_action, "finger.huanyin" :),
        (: exert_function, "powerup": ),
        (: smart_fight() :)
    }));

    set_temp("apply/attack", 1000);
    set_temp("apply/defense", 2000);
    set_temp("apply/damage", 1000);
    set_temp("apply/unarmed_damage", 1000);
    set_temp("apply/armor", 5000);
    set_temp("apply/reduce_damage", 90);
    set_temp("apply/reduce_busy", 36);
    set_temp("apply/add_busy", 15);

    set("death_msg", (: death_msg :));
    set("rewards", ([
        "exp": 100000,
        "pot": 50000,
        "mar": 10000,
        "score": 300,
        "gold": 5
        ]));

    set("drops", ([
        "RA&RANDOM60"    :       50,    // 低級普通裝備
        "RA&RANDOM70"    :       30,    // 低級普通裝備
        "FI&/clone/tessera/rune21" :   30,
        "FI&/clone/goods/enchant-scroll" :   40,
        "FI&/clone/goods/sun"   :   50,
        "FI&/clone/goods/sun"   :   50,
        "FI&/clone/goods/moon"  :   50,
        "FI&/clone/goods/moon"  :   50,
        "FI&/clone/tessera/rune12"  :   1,
        "FI&/clone/tongren/tongren" + (1 + random(2)):              1
        ]));

    setup();

    carry_object("/kungfu/class/songshan/obj/yellow-cloth")->wear();
    set_temp("born_time", time());
    if (clonep()) keep_heart_beat();
}

int accept_fight(object ob) {
    kill_ob(ob);
    return -1;
}

int accept_kill(object ob) {
    return 1;
}

int accept_hit(object ob) {
    kill_ob(ob);
    return -1;
}

mixed hit_ob(object me, object ob, int damage_bouns) {
    ob->start_busy(5 + random(6));
    //me->receive_wound("qi", 500 + random(600), ob);
    return HIY "$N" HIY "怒喝一聲，奮力反抗，竟逼得$n" HIY "手忙腳亂。\n" NOR;
}

void heart_beat() {
    if (query("neili") < 1 && random(10) == 1)
        set("neili", query("max_neili"));

    return ::heart_beat();
}

void random_move() {
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

void death_msg() {
    command("mess 我還不能死，我要親手覆滅明教，師妹，大仇得報的時候，我就去見你...");
}

void smart_fight() {
    object me;
    object target;
    string msg;
    int damage;

    target = select_opponent();
    me = this_object();

    damage = damage_power(me, "finger");
    damage *= 120;

    msg = HIR "$N低垂的眼簾往上揚起，露出一對深邃難測，陰狠冰冷的目光，接著灰色的僧袍往下凹陷，緊貼全身，一指點出。"
    "動作行雲流水，又若羚羊掛角，玄機暗含。一指彙集了全身的內力，瞬時全身衣衫再次鼓脹，雙目放出驚人的光芒，"
    "在$n尚自吃驚之際，$N的一指已如流星閃電般襲至，同時伴隨的還有刺骨的寒氣和無盡的陰毒之風，$n只覺的周"
    "圍的空氣似乎都在霎那間凝固了，渾身似乎有冰蠶在血脈中爬行，甚至發出噝噝的輕聲...\n" NOR;

    msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 500,
        HIR"\n$n被$N的冰寒指力點中，真氣瞬間渙散無法凝聚，全身冰冷入骨，臉色發青，不由得吐出一大口鮮血，飛出倒地！\n" NOR);

    message_combatd(sort_msg(msg), me, target);

    return;
}
