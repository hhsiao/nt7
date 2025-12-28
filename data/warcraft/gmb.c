// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍女[2;37;0m[2;37;0m", ({"gmblong"}));        
        set("gender", "女性");                
        set("long", "喔喔[2;37;0m
它是黃蓉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gmb");
        set("owner_name", "黃蓉");
        set_temp("owner", "gmb");
        set_temp("owner_name", "黃蓉");
        ::setup();
}
