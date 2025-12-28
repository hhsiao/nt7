// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m陳水扁[2;37;0m[2;37;0m", ({"noos"}));        
        set("gender", "男性");                
        set("long", "臺北市議員、立法院立法委員、臺北市市長。[2;37;0m
它是馬英九的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "nos");
        set("owner_name", "馬英九");
        set_temp("owner", "nos");
        set_temp("owner_name", "馬英九");
        ::setup();
}
