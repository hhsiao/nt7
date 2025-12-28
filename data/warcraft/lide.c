// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛行者[2;37;0m[2;37;0m", ({"lxa"}));        
        set("gender", "男性");                
        set("long", "飛行者[2;37;0m
它是煉雲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lide");
        set("owner_name", "煉雲");
        set_temp("owner", "lide");
        set_temp("owner_name", "煉雲");
        ::setup();
}
