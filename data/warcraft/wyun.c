// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小了個白[2;37;0m[2;37;0m", ({"wlong"}));        
        set("gender", "男性");                
        set("long", "小了個白[2;37;0m
它是魯山的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wyun");
        set("owner_name", "魯山");
        set_temp("owner", "wyun");
        set_temp("owner_name", "魯山");
        ::setup();
}
