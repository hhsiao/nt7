// REDGIRL.C
#include <ansi.h>
inherit NPC;
void create() {
    set_name("小香", ({ "xiang" }) );
    set("long", "這是一個美麗的少女，但眉眼中卻蘊著淡淡的憂傷。\n");
    set("age", 16);
    set("gender", "女性");
    set("attitude", "peaceful");
    setup();
    carry_object(__DIR__"obj/cloth2")->wear();
}
