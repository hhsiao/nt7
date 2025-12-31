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
    set_name("左冷禪", ({ "zuo lengchan", "zuo" }) );
    set("title", HIR"五嶽劍派盟主"HIY"嵩山派第十三代掌門"NOR);
    set("gender", "男性");
    set("class", "swordsman");
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

    set_skill("cuff", 1200);
    set_skill("strike", 1200);
    set_skill("sword", 1200);
    set_skill("force", 1200);
    set_skill("parry", 1200);
    set_skill("dodge", 1200);
    set_skill("lingxu-bu", 1200);
    set_skill("songshan-jian", 1200);
    set_skill("lingyun-jian", 1200);
    set_skill("chuanyue-jian", 1200);
    set_skill("jiuqu-jian", 1200);
    set_skill("poyang-jian", 1200);
    set_skill("songshan-xinfa", 1200);
    set_skill("hanbing-zhenqi", 1200);
    set_skill("hanbing-zhang", 1200);
    set_skill("songshan-zhang", 1200);
    set_skill("songshan-quan", 1200);
    set_skill("literate", 1200);
    set_skill("martial-cognize", 1200);

    map_skill("force", "hanbing-zhenqi");
    map_skill("sword", "poyang-jian");
    map_skill("parry", "poyang-jian");
    map_skill("strike", "hanbing-zhang");
    map_skill("cuff", "songshan-quan");
    map_skill("dodge", "lingxu-bu");

    prepare_skill("strike", "hanbing-zhang");

    create_family("嵩山派", 13, "掌門");

    set("chat_chance", 30);
    set("chat_msg", ({
    //(: random_move :),
        "只有五嶽並派，我為盟主，五嶽劍派方可與少林、武當鼎足而三，此乃千秋大事啊。\n "
    }));
    set("chat_chance_combat", 120);
    set("chat_msg_combat", ({
        (: perform_action, "sword.long" :),
        (: perform_action, "sword.xian" :),
        (: perform_action, "strike.heng" :),
        (: perform_action, "strike.han" :),
        (: exert_function, "recover": ),
        (: exert_function, "powerup": ),
        (: exert_function, "freezing": ),
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

    //set("death_msg", (: death_msg :));
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
        "FI&/clone/tongren/tongren" + (1 + random(2)):              1,
        "FI&/clone/misc/baoxiang" : 100
        ]));

    setup();

    carry_object("/clone/weapon/changjian")->wield();
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
    command("chat 怎麼可能，我是五嶽劍派盟主，正教三大高手，豈會敗於小輩之手...！");
}

void smart_fight() {
    object me;
    object target;
    string msg;
    int damage;

    target = select_opponent();
    me = this_object();

    damage = damage_power(me, "strike");
    damage *= 120;

    msg = HIB "$N一聲長嘯，四周空間溫度驟降，寒氣瞬間侵體，同時$N雙掌飛舞，龍捲風般往$n旋轉過去。交織出寒風冰芒、掌風似刀，攻守兼備的罩網。"
    "奇異冰冷的勁氣，以$N為中心像冬日沙漠颳起的狂暴冰寒般，隨著$N雙掌的迫近，以雷霆萬鈞之勢往$n襲去。不止冷風入體即傷，最厲害處也"
    "是$N雙掌每個旋轉速度都有微妙的差異，教人難以預先掌握攻勢襲體的精準時間。四周的一切似乎都被這冰寒之氣冷凝住了，$n只覺得真氣也無"
    "法轉動，大駭之下，掌風寒氣已遮天蓋地而來，一時之間，心神懼喪，竟無法出招。\n" NOR;

    msg += COMBAT_D->do_damage(me, target, SPECIAL_ATTACK, damage, 500,
        HIR"\n$n霎時只覺得寒風襲體，有種說不出的難受。尚未來得及運功驅除寒意，雙掌已擊至胸前，只聽咔咔的骨折聲，噴出大口的鮮血，飛出倒地！\n" NOR);

    message_combatd(sort_msg(msg), me, target);

    return;
}
