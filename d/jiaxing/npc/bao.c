//bao.c

inherit NPC;
#include <ansi.h>

void create() {
    set_name("包惜弱", ({ "bao xiruo", "bao", "xiruo" }) );
    set("gender", "女性" );
    set("age", 25);
    set("long",
        "她身材極好，雖然臉有點黑，但是還是看出無限的嫵媚動人。\n");
    set("str", 10);
    set("dex", 10);
    set("con", 5);
    set("int", 5);
    set("per", 30);
    set("shen_type", 1);
    set_skill("unarmed", 5);

    set("combat_exp", 15000);
    set("max_qi", 100);
    set("max_jing", 100);
    set("max_neili", 0);
    set("eff_jingli", 200);
    set("qi", 100);
    set("jing", 100);
    set("jingli", 200);
    set("neili", 0);

    set("inquiry", ([
        "郭嘯天" : "他是我夫君義兄。",
        "楊康" : "這是一個道人給我未出世的兒女取的名字。",
        "郭靖" : "這是我夫君義兄郭嘯天的骨肉。",
        "李萍" : "她是我嫂子"
        ]));

    setup();
    carry_object("/clone/cloth/cloth.c")->wear();
    carry_object("/clone/cloth/shoes.c")->wear();
}
