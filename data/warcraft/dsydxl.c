// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小青龍[2;37;0m[2;37;0m", ({"dsy"}));        
        set("gender", "男性");                
        set("long", "這是一隻青龍幼崽[2;37;0m
它是鐵錘的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dsydxl");
        set("owner_name", "鐵錘");
        set_temp("owner", "dsydxl");
        set_temp("owner_name", "鐵錘");
        ::setup();
}
