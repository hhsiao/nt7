// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m殺氣[2;37;0m[1;32m騰[1;35m騰[2;37;0m[2;37;0m", ({"cruel"}));        
        set("gender", "男性");                
        set("long", "殺氣騰騰[2;37;0m
它是火騰騰的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "burning");
        set("owner_name", "火騰騰");
        set_temp("owner", "burning");
        set_temp("owner_name", "火騰騰");
        ::setup();
}
