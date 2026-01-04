#include <armor.h>
#include <ansi.h>

int is_xunzhang() { return 1; }
inherit MEDAL;

void create() {
    set_name(HIW "鑽石勳章" NOR, ({ "diamond xunzhang", "diamond", "xunzhang", "medal" }));
    set("long", HIW "為泥潭做出重大貢獻而獲得的勳章，非常珍貴，乃睿者的象徵。\n" NOR);
    set_weight(500);
    set("unit", "枚");
    set("value", 200000);
    set("material", "gold");
    set("armor_prop/learn_times", 300);
    set("armor_prop/research_times", 500);
    set("armor_prop/practice_times", 500);
    set("armor_prop/derive_times", 500);
    set("enchase/SN", "dm1");
    set("bindable", 1);     // 裝備綁定
    set("auto_load", 1);
    setup();
}
