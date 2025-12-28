// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("畢碧碧[2;37;0m[2;37;0m", ({"yaobbb"}));        
        set("gender", "男性");                
        set("long", "畢碧碧[2;37;0m
它是藥嗶嗶的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaobb");
        set("owner_name", "藥嗶嗶");
        set_temp("owner", "yaobb");
        set_temp("owner_name", "藥嗶嗶");
        ::setup();
}
