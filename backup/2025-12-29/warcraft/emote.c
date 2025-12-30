// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白馬[2;37;0m[2;37;0m", ({"myhorse"}));        
        set("gender", "男性");                
        set("long", "白馬[2;37;0m
它是表情黨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "emote");
        set("owner_name", "表情黨");
        set_temp("owner", "emote");
        set_temp("owner_name", "表情黨");
        ::setup();
}
