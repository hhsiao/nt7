// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("練草[2;37;0m[2;37;0m", ({"lidna"}));        
        set("gender", "男性");                
        set("long", "練草[2;37;0m
它是煉花的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidn");
        set("owner_name", "煉花");
        set_temp("owner", "lidn");
        set_temp("owner_name", "煉花");
        ::setup();
}
