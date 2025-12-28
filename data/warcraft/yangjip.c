// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m青兒[2;37;0m[2;37;0m", ({"qinger"}));        
        set("gender", "女性");                
        set("long", "一條碧綠青蛇[2;37;0m
它是千夜的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yangjip");
        set("owner_name", "千夜");
        set_temp("owner", "yangjip");
        set_temp("owner_name", "千夜");
        ::setup();
}
