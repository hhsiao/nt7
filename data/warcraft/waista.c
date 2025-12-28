// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("泰古[2;37;0m[2;37;0m", ({"waistalong"}));        
        set("gender", "男性");                
        set("long", "開古[2;37;0m
它是腰帶倉一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "waista");
        set("owner_name", "腰帶倉一");
        set_temp("owner", "waista");
        set_temp("owner_name", "腰帶倉一");
        ::setup();
}
