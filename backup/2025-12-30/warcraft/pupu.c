// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m好吃叫化雞[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "$HIG$好吃叫化雞[2;37;0m
它是伏貓降蛇的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pupu");
        set("owner_name", "伏貓降蛇");
        set_temp("owner", "pupu");
        set_temp("owner_name", "伏貓降蛇");
        ::setup();
}
