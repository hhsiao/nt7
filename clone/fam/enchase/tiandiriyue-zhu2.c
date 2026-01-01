#include <ansi.h>
inherit TESSERA;

void create()
{
        set_name(HIY "天地日月靈珠" NOR, ({"tiandi riyuezhu", "tiandi", "riyuezhu" }));
        set_weight(900);
        set("long", HIY "一顆晶瑩通透，猶露欲滴的寶石，世間罕見。。\n" NOR);
                set("unit", "顆");
                set("value", 5000);
                set("enchase/name", "天地日月靈珠");
                set("enchase/point", 1);
                set("enchase/type", "armor");
                set("can_be_qiling", 1);
        setup();
}

int query_autoload()
{
        return 1;
}
