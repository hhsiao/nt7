// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("筋斗雲[2;37;0m[2;37;0m", ({"jdy"}));        
        set("gender", "男性");                
        set("long", "筋斗雲[2;37;0m
它是紙鳶紛飛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "skyamm");
        set("owner_name", "紙鳶紛飛");
        set_temp("owner", "skyamm");
        set_temp("owner_name", "紙鳶紛飛");
        ::setup();
}
