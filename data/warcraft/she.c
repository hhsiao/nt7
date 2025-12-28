// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m綠帽擼祖[2;37;0m[2;37;0m", ({"rcdll"}));        
        set("gender", "女性");                
        set("long", "ereewww[2;37;0m
它是段星星的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "she");
        set("owner_name", "段星星");
        set_temp("owner", "she");
        set_temp("owner_name", "段星星");
        ::setup();
}
