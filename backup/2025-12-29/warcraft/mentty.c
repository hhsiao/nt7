// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m擼啦[2;37;0m[2;37;0m", ({"menttyo"}));        
        set("gender", "女性");                
        set("long", "坑爹的，又被擼啦！！！[2;37;0m
它是無塵劍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mentty");
        set("owner_name", "無塵劍");
        set_temp("owner", "mentty");
        set_temp("owner_name", "無塵劍");
        ::setup();
}
