// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"xhdf"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是簡單就好的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cdcdx");
        set("owner_name", "簡單就好");
        set_temp("owner", "cdcdx");
        set_temp("owner_name", "簡單就好");
        ::setup();
}
