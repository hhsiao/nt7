// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("妞妞[2;37;0m[2;37;0m", ({"cause"}));        
        set("gender", "男性");                
        set("long", "妞妞[2;37;0m
它是鍾一的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lowek");
        set("owner_name", "鍾一");
        set_temp("owner", "lowek");
        set_temp("owner_name", "鍾一");
        ::setup();
}
