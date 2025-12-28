// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m幻[2;37;0m[2;37;0m", ({"huanhuan"}));        
        set("gender", "男性");                
        set("long", "夢幻之聖獸[2;37;0m
它是鐵中棠的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jdc");
        set("owner_name", "鐵中棠");
        set_temp("owner", "jdc");
        set_temp("owner_name", "鐵中棠");
        ::setup();
}
