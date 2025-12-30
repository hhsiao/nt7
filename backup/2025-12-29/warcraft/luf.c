// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m搖錢樹[2;37;0m[2;37;0m", ({"qlong"}));        
        set("gender", "男性");                
        set("long", "搖錢樹[2;37;0m
它是採花五的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "luf");
        set("owner_name", "採花五");
        set_temp("owner", "luf");
        set_temp("owner_name", "採花五");
        ::setup();
}
