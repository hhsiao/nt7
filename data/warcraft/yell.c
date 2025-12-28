// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m青冥獸[2;37;0m[2;37;0m", ({"doo"}));        
        set("gender", "男性");                
        set("long", "坐騎[2;37;0m
它是卓玉琴的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yell");
        set("owner_name", "卓玉琴");
        set_temp("owner", "yell");
        set_temp("owner_name", "卓玉琴");
        ::setup();
}
