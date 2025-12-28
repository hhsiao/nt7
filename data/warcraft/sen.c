// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m皇者寶座[2;37;0m[2;37;0m", ({"huang"}));        
        set("gender", "男性");                
        set("long", "皇者寶座[2;37;0m
它是羅賓森的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sen");
        set("owner_name", "羅賓森");
        set_temp("owner", "sen");
        set_temp("owner_name", "羅賓森");
        ::setup();
}
