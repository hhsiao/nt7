// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大鼻龍[2;37;0m[2;37;0m", ({"skk"}));        
        set("gender", "男性");                
        set("long", "大鼻龍[2;37;0m
它是小二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "scaipy");
        set("owner_name", "小二");
        set_temp("owner", "scaipy");
        set_temp("owner_name", "小二");
        ::setup();
}
