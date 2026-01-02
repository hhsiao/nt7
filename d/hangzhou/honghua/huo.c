#include <ansi.h>

inherit NPC;
inherit F_MASTER;

mixed ask_skill1();

void create() {
    set_name("霍青桐", ({ "huo qingtong", "huo", "qingtong" }));
    set("long", @LONG
這女郎秀美中透著一股英氣，光采照人，當真
麗若春梅綻雪，神如秋蕙披霜，兩頰融融，霞
映澄塘，雙目晶晶，月射寒江。腰插匕首，長
辨垂肩，鵝黃衫子，頭戴金絲繡的小帽，帽邊
插了根長長的翠綠羽毛，革履青馬，旖旎如畫。
LONG);
    set("nickname", HIG "翠羽黃衫" NOR);
    set("gender", "女性");
    set("class", "swordsman");
    set("age", 18);
    set("attitude", "friendly");
    set("shen_type", 1);
    set("per", 30);
    set("str", 30);
    set("int", 30);
    set("con", 30);
    set("dex", 30);

    set("max_qi", 2800);
    set("max_jing", 1500);
    set("neili", 2500);
    set("max_neili", 2500);
    set("jiali", 150);
    set("combat_exp", 800000);

    set_skill("force", 180);
    set_skill("zhanshen-xinjing", 100);
    set_skill("tianchi-neigong", 180);
    set_skill("dodge", 180);
    set_skill("yanzi-chuanyun", 160);
    set_skill("zhuangzi-wu", 180);
    set_skill("parry", 160);
    set_skill("sword", 180);
    set_skill("sanfen-jianshu", 180);
    set_skill("hand", 160);
    set_skill("yunlong-shou", 160);
    set_skill("claw", 160);
    set_skill("yunlong-zhua", 160);
    set_skill("martial-cognize", 160);
    set_skill("literate", 200);
    set_skill("muslim", 300);

    map_skill("force", "tianchi-neigong");
    map_skill("dodge", "zhuangzi-wu");
    map_skill("hand", "yunlong-shou");
    map_skill("parry", "sanfen-jianshu");
    map_skill("claw", "yunlong-zhua");
    map_skill("sword", "sanfen-jianshu");

    prepare_skill("hand", "yunlong-shou");
    prepare_skill("claw", "yunlong-zhua");

    create_family("天山派", 16, "傳人");

    set("chat_chance_combat", 120);
    set("chat_msg_combat", ({
        (: perform_action, "sword.haishi" :),
        (: perform_action, "dodge.hua" :),
        (: exert_function, "recover": )
    }));

    set("inquiry", ([
        "海市蜃樓" : (: ask_skill1 :)
        ]));

    set_temp("apply/damage", 100);
    set_temp("apply/unarmed_damage", 100);
    set_temp("apply/armor", 200);

    setup();
    carry_object(__DIR__"obj/cuiyu")->wear();
    carry_object(__DIR__"obj/huangshan")->wear();
    carry_object(__DIR__"obj/shortsword")->wield();
}

mixed ask_skill1() {
    object me;

    me = this_player();
    if(query("can_perform/sanfen-jianshu/haishi", me) )
        return "咦？你不是已經會了嗎？";

    if(!query("story/sanfenjian", me) )
        return "你這是什麼意思？";

    if (me->query_skill("sanfen-jianshu", 1) < 150)
        return "你的三分劍術還不到家，要多練練！";

    message_vision(HIY "$n" HIY "點了點頭，拔出手中" NOR +
        HIC "短劍" NOR + HIY "，突然圈轉，一"
        "招之中另蘊涵三招，招式繁複狠辣，劍"
        "招虛虛\n實實，正是三分劍術的獨得之秘"
        "——「海市蜃樓」。\n" NOR,
        me, this_object());
    command("nod");
    command("say 你可明白了？");
    tell_object(me, HIC "你學會了「海市蜃樓」。\n" NOR);
    if (me->can_improve_skill("sword"))
        me->improve_skill("sword", 350000);
    set("can_perform/sanfen-jianshu/haishi", 1, me);
    return 1;
}

int recognize_apprentice(object me, string skill) {
    if (skill != "muslim")
    {
        command("say 找你師父去，別來煩我。");
        return -1;
    }

    if(!query_temp("can_learn/huoqingtong", me) )
    {
        command("sigh");
        command("say 我就教你一些迴文，假如你哪時見到"
            "紅…唉，還是算了吧。");
        set_temp("can_learn/huoqingtong", 1, me);
    }

    return 1;
}

void unconcious() {
    die();
}
