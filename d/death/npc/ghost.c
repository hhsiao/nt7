#include <ansi.h>
inherit NPC;
void create() {
    set_name("亡魂", ({ "ghost" }) );
    set("long", HIB "\n\n一個死者的魂魄。\n" NOR);
    set("attitude", "peaceful");
    set("title", HIB "(鬼氣)" NOR);

    setup();
}

varargs int receive_damage(string type, int n, object who) {
    return 0;
}

varargs int receive_wound(string type, int n, object who) {
    return 0;
}
