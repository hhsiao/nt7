#include <ansi.h>
inherit TESSERA;

void create()
{
        set_name(HIR "麒麟聖火" NOR, ({"qilin shenghuo", "qilin", "shenghuo" }));
        set_weight(1000);
        set("unit", "顆");
                set("value", 500000);
                set("long", HIR "據說麒麟火麒麟神獸骸骨所化，拿在手中有種熾熱的感覺。\n" NOR);
                set("enchase/name", "麒麟聖火");
                set("enchase/point", 5);
                set("enchase/type", "wrists");
                set("can_be_qiling", 1);
        setup();
}

int query_autoload()
{
        return 1;
}
