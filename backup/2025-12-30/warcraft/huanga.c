// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("奪要[2;37;0m[2;37;0m", ({"asdf"}));        
        set("gender", "男性");                
        set("long", "奪要[2;37;0m
它是大刀向東的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "huanga");
        set("owner_name", "大刀向東");
        set_temp("owner", "huanga");
        set_temp("owner_name", "大刀向東");
        ::setup();
}
