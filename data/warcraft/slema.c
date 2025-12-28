// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "女性");                
        set("long", "一隻雌性的小青龍[2;37;0m
它是緋月的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "slema");
        set("owner_name", "緋月");
        set_temp("owner", "slema");
        set_temp("owner_name", "緋月");
        ::setup();
}
