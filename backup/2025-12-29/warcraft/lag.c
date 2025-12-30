// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玉佛珠[2;37;0m[2;37;0m", ({"out"}));        
        set("gender", "女性");                
        set("long", "此物品未鑑定[2;37;0m
它是趙靈兒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lag");
        set("owner_name", "趙靈兒");
        set_temp("owner", "lag");
        set_temp("owner_name", "趙靈兒");
        ::setup();
}
