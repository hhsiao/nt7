// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雜毛龍[2;37;0m[2;37;0m", ({"ookk"}));        
        set("gender", "男性");                
        set("long", "被人天天騎的畜生[2;37;0m
它是趙小婉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zwy");
        set("owner_name", "趙小婉");
        set_temp("owner", "zwy");
        set_temp("owner_name", "趙小婉");
        ::setup();
}
