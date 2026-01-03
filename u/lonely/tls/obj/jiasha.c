#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIY "金絲木棉袈裟" NOR, ({ "jia sha", "cloth","jiasha" }) );
        set_weight(8000);
                set("long", "這是一件用金絲鑲邊的灰色木棉袈裟。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 40);
                set("wear_msg","‘譁’的一聲，眼前金光一閃，$N披上一件$n，古色斑斕，金絲盤繡。\n");
                set("remove_msg","$N把$n從身上脫了下來。\n");
                set("tianlongsi",1);
        setup();
}
