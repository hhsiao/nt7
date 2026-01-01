#include <armor.h>
#include <ansi.h>

int is_xunzhang() { return 1; }
inherit MEDAL;

void create()
{
        set_name(HIC "新銳青銅勳章" NOR, ({ "xinrui bronze medal", "xinrui", "xunzhang" }));
        set("long", HIC "華山論劍新銳組第三獲得的勳章，非常珍貴，乃少年強者的象徵。\n" NOR);
        set_weight(500);
        set("unit", "枚");
                set("value", 100000);
                set("material", "bronze");
                set("armor_prop/research_times", 100);
                //set("armor_prop/practice_times", 100);
                //set("armor_prop/derive_times", 100);
        set("enchase/SN", "xr3");
        set("bindable", 2);
        set("auto_load", 1);
        setup();
}
