// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m無色牛[2;37;0m[2;37;0m", ({"niu"}));        
        set("gender", "男性");                
        set("long", "無色牛[2;37;0m
它是黃飛虎的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xycode");
        set("owner_name", "黃飛虎");
        set_temp("owner", "xycode");
        set_temp("owner_name", "黃飛虎");
        ::setup();
}
