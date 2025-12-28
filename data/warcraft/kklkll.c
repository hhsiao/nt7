// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("還得靠[2;37;0m[2;37;0m", ({"odje"}));        
        set("gender", "男性");                
        set("long", "還得靠[2;37;0m
它是記錄路徑的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kklkll");
        set("owner_name", "記錄路徑");
        set_temp("owner", "kklkll");
        set_temp("owner_name", "記錄路徑");
        ::setup();
}
