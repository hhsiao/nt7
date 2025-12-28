// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"sdfsa"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是赫連天成的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "bagbagd");
        set("owner_name", "赫連天成");
        set_temp("owner", "bagbagd");
        set_temp("owner_name", "赫連天成");
        ::setup();
}
