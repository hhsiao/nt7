// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("錢大款[2;37;0m[2;37;0m", ({"golds"}));        
        set("gender", "男性");                
        set("long", "錢大款[2;37;0m
它是採花六的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lum");
        set("owner_name", "採花六");
        set_temp("owner", "lum");
        set_temp("owner_name", "採花六");
        ::setup();
}
