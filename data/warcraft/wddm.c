// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("三大類[2;37;0m[2;37;0m", ({"benz"}));        
        set("gender", "男性");                
        set("long", "           [2;37;0m
它是武當米的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wddm");
        set("owner_name", "武當米");
        set_temp("owner", "wddm");
        set_temp("owner_name", "武當米");
        ::setup();
}
