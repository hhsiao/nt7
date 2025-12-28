// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m金礦[2;37;0m[2;37;0m", ({"qwe"}));        
        set("gender", "男性");                
        set("long", "Money[2;37;0m
它是金貳的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cashb");
        set("owner_name", "金貳");
        set_temp("owner", "cashb");
        set_temp("owner_name", "金貳");
        ::setup();
}
