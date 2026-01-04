// armor.c
#include <armor.h>
inherit EQUIP;

int is_armor() { return 1; }
void setup() {
    set("armor_type", TYPE_ARMOR);
    ::setup();
}
