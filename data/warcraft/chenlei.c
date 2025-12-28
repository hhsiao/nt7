// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("藍龍[2;37;0m[2;37;0m", ({"bluedragon"}));        
        set("gender", "男性");                
        set("long", "惡魔坐騎[2;37;0m
它是軒轅無痕的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "chenlei");
        set("owner_name", "軒轅無痕");
        set_temp("owner", "chenlei");
        set_temp("owner_name", "軒轅無痕");
        ::setup();
}
