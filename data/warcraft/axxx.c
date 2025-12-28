// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m青龍[2;37;0m[2;37;0m", ({"aaxx"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是不知名的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "axxx");
        set("owner_name", "不知名");
        set_temp("owner", "axxx");
        set_temp("owner_name", "不知名");
        ::setup();
}
