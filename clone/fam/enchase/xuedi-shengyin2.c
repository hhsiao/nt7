#include <ansi.h>
inherit TESSERA;

void create()
{
        set_name(HIW "雪地聖音" NOR, ({"xuedi shengyin", "xuedi", "shengyin"}));
        set_weight(2000);
        set("long", HIW "人間罕有的寶石，據說在極寒雪地形成。\n" NOR);
        set("unit", "顆");
                set("value", 500000);
                set("enchase/name", "雪地聖音");
                set("enchase/point", 1);
                set("enchase/type", "cloth");
                set("can_be_qiling", 1);
        setup();
}

int query_autoload()
{
        return 1;
}
