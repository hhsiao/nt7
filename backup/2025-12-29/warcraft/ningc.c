// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m寧傘傘傘[2;37;0m[2;37;0m", ({"ningccc"}));        
        set("gender", "男性");                
        set("long", "$HIB$寧傘傘傘[2;37;0m
它是寧三的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ningc");
        set("owner_name", "寧三");
        set_temp("owner", "ningc");
        set_temp("owner_name", "寧三");
        ::setup();
}
