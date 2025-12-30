// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("練練[2;37;0m[2;37;0m", ({"lidda"}));        
        set("gender", "女性");                
        set("long", "練練[2;37;0m
它是煉雷的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidi");
        set("owner_name", "煉雷");
        set_temp("owner", "lidi");
        set_temp("owner_name", "煉雷");
        ::setup();
}
