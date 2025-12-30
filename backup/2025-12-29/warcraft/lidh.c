// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶馬[2;37;0m[2;37;0m", ({"lidhh"}));        
        set("gender", "男性");                
        set("long", "寶馬[2;37;0m
它是煉空的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidh");
        set("owner_name", "煉空");
        set_temp("owner", "lidh");
        set_temp("owner_name", "煉空");
        ::setup();
}
