// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("練花[2;37;0m[2;37;0m", ({"lidmm"}));        
        set("gender", "男性");                
        set("long", "練花[2;37;0m
它是煉米飛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidm");
        set("owner_name", "煉米飛");
        set_temp("owner", "lidm");
        set_temp("owner_name", "煉米飛");
        ::setup();
}
