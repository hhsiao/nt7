// yunshang.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create() {
    set_name(HIG "雲裳" NOR, ({ "yunshang" }));
    set("long", "這是一件織女裁剪西天之雲織成的雲裳。\n");
    set_weight(10);
    set("material", "cloth");
    set("unit", "件");
    set("value", 1);
    set("armor_prop/armor", 1);
    setup();
}
