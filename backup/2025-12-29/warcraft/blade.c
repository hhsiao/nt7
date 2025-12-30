// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("狂風[2;37;0m[2;37;0m", ({"oko"}));        
        set("gender", "男性");                
        set("long", "厲害的[2;37;0m
它是小李飛刀的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "blade");
        set("owner_name", "小李飛刀");
        set_temp("owner", "blade");
        set_temp("owner_name", "小李飛刀");
        ::setup();
}
