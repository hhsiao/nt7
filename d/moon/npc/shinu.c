// REDGIRL.C
#include <ansi.h>
inherit NPC;
void create() {
    set_name("侍女", ({ "shinu" }) );
    set("title", "圓月山莊");
    set("long", "這是一個美麗清純的少女。\n");
    set("age", 16);
    set("gender", "女性");
    set("attitude", "peaceful");
    set("chat_chance", 10);
    set("chat_msg", ({
        "侍女衝著你笑了笑，露出兩個迷人的小酒窩。\n",
        (: random_move :)
    }) );
    setup();
    carry_object(__DIR__"obj/cloth2")->wear();
}
