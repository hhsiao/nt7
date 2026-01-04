
#include <ansi.h>

inherit ITEM;

int is_tongren() { return 1; }
void create() {
    set_name(YEL "衝穴銅人·陰蹺脈·屬兌穴" NOR, ({ "tongren a18", "tongren" }));
    set_weight(50);

    set("unit", "個");
    set("long", NOR + YEL "這是一個衝穴銅人，上面繪製了一些經絡穴位圖案，以及衝穴使用方法。\n" NOR);
    set("value", 10000);
    set("material", "steal");

    set("jingmai_name", "陰蹺脈");
    set("xuewei_name", "屬兌穴");
    set("chongxue_xiaoguo", "NEI:20");
    set("neili_cost", "150");
    setup();
}
