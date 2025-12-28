// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("城唇形[2;37;0m[2;37;0m", ({"sdfg"}));        
        set("gender", "男性");                
        set("long", "城唇形[2;37;0m
它是枯奪的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "huangd");
        set("owner_name", "枯奪");
        set_temp("owner", "huangd");
        set_temp("owner_name", "枯奪");
        ::setup();
}
