// This program is a part of NT MudLIB
// ab_crystal.c 能力水晶

#include <ansi.h>

inherit ITEM;

int is_spe_crystal() { return 1; }
void create() {
    set_name(HIY"超能力水晶"NOR, ({ "ability2 crystal", "ability2", "crystal" }) );
    set_weight(1);
    set("long", HIY "表面泛著金色光芒的超能力水晶，是一個儲存著強化星級、改造品級\n"
        HIY "及套裝等級諸多能量的水晶，在干將處可實現不需任何其他材料就能\n"
        HIY "讓新簽名的裝備擁有同樣的強化星級、改造品級及套裝等級。\n" NOR);
    set("value", 50000);
    set("unit", "塊");
    set("qianghua_level", 9);
    set("set_data", 1);
    set("autoload", 1);
    setup();
}

string extra_long() {
    string str;

    if(!query("set_data") ) return "";
    str = sprintf(HIM "\n能量存儲\n" NOR);
    str += sprintf(WHT "改造品級 : %d\n" NOR, query("reform_level"));
    str += sprintf(WHT "強化星級 : %d\n" NOR, query("qianghua_level"));
    str += sprintf(WHT "套裝等級 : %d\n" NOR, query("upsuit_level"));
    return str;
}
