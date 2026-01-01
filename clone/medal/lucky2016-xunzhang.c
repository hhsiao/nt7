
#include <armor.h>
#include <ansi.h>

int is_xunzhang() { return 1; }
inherit MEDAL;

void create()
{
        set_name(HIM "幸運勳章" NOR, ({ "lucky xunzhang", "lucky", "xunzhang" }));
        set("long", HIM "祝福您在2016年幸運通達、吉祥如意的勳章，非常珍貴，乃幸運吉祥的象徵。\n" NOR);
        set_weight(500);
        set("unit", "枚");
                set("value", 200000);
                set("material", "bronze");
                set("armor_prop/armor", 21000);
                set("armor_prop/magic_find", 100);
                set("armor_prop/lucky2016", 1);
                set("special/desc", HIR "佩帶後可增加突破每次技能升級上限的機會。" NOR);
        set("enchase/SN", "jxxz");
        setup();
}

int query_autoload()
{
        return 1;
}
