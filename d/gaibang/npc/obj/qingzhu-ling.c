#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(NOR + GRN "青竹令" NOR, ({ "qingzhu ling", "qingzhu", "ling" }));
        set_weight(500);
        set("unit", "面");
                set("long", GRN "這是一面用青竹做成的令牌，憑此可向幫內"
                            "師兄挑戰。\n" NOR);
                set("material", "steel");
                set("no_sell", "這是啥？也能賣錢？");
}
