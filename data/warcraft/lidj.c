// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("練氣[2;37;0m[2;37;0m", ({"lidjj"}));        
        set("gender", "男性");                
        set("long", "練氣[2;37;0m
它是煉電的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidj");
        set("owner_name", "煉電");
        set_temp("owner", "lidj");
        set_temp("owner_name", "煉電");
        ::setup();
}
