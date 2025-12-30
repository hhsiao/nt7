// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("太古兇獸[2;37;0m[2;37;0m", ({"clothblong"}));        
        set("gender", "男性");                
        set("long", "電腦[2;37;0m
它是甲無碼的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "armora");
        set("owner_name", "甲無碼");
        set_temp("owner", "armora");
        set_temp("owner_name", "甲無碼");
        ::setup();
}
