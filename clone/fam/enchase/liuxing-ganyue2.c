#include <ansi.h>
inherit TESSERA;

void create() {
    set_name(HIY "流星趕月" NOR, ({"liuxing ganyue", "liuxing", "ganyue"}));
    set_weight(2000);
    set("long", HIY "人間罕有的寶石，據說乃天上流星墜落後形成。\n" NOR);
    set("unit", "顆");
    set("value", 500000);
    set("enchase/name", "流星趕月");
    set("enchase/point", 1);
    set("enchase/type", "boots");
    set("can_be_qiling", 1);
    setup();
}

int query_autoload() {
    return 1;
}
