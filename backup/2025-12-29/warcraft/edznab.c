// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m獸獸[2;37;0m[2;37;0m", ({"sshou"}));        
        set("gender", "男性");                
        set("long", "獸獸是也[2;37;0m
它是古越龍山的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "edznab");
        set("owner_name", "古越龍山");
        set_temp("owner", "edznab");
        set_temp("owner_name", "古越龍山");
        ::setup();
}
