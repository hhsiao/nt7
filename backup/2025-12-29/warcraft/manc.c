// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"ffff"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是大力一號的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "manc");
        set("owner_name", "大力一號");
        set_temp("owner", "manc");
        set_temp("owner_name", "大力一號");
        ::setup();
}
