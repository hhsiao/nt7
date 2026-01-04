inherit ITEM;
#include <ansi.h>

void create() {
    set_name(HIC "天殘玉" NOR, ({"tiancan yu", "tiancan", "yu"}));
    set_weight(300);
    set("long", HIC "這是一塊晶瑩剔透的勾玉，珍貴無比。\n" NOR);
    set("unit", "塊");
    set("value", 15000);
    setup();
}

int query_autoload() {
    return 1;
}
