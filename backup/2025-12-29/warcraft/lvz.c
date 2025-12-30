// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m綠竹[2;37;0m[2;37;0m", ({"lvzs"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是綠珠的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lvz");
        set("owner_name", "綠珠");
        set_temp("owner", "lvz");
        set_temp("owner_name", "綠珠");
        ::setup();
}
