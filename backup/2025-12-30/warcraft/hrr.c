// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[33m拉[33m土[33m車[2;37;0m[2;37;0m", ({"hrrs"}));        
        set("gender", "男性");                
        set("long", "花絨絨的專用車[2;37;0m
它是花絨絨的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hrr");
        set("owner_name", "花絨絨");
        set_temp("owner", "hrr");
        set_temp("owner_name", "花絨絨");
        ::setup();
}
