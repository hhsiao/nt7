// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m飛龍在天[2;37;0m[2;37;0m", ({"lon"}));        
        set("gender", "男性");                
        set("long", "飛龍啊，在天上翱翔吧[2;37;0m
它是龍空無畏的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "asword");
        set("owner_name", "龍空無畏");
        set_temp("owner", "asword");
        set_temp("owner_name", "龍空無畏");
        ::setup();
}
