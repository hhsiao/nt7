// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("藍藍[2;37;0m[2;37;0m", ({"haishui"}));        
        set("gender", "男性");                
        set("long", "藍色[2;37;0m
它是黃譽的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "haifeng");
        set("owner_name", "黃譽");
        set_temp("owner", "haifeng");
        set_temp("owner_name", "黃譽");
        ::setup();
}
