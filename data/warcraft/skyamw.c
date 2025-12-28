// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("筋斗雲[2;37;0m[2;37;0m", ({"jdy"}));        
        set("gender", "男性");                
        set("long", "筋斗雲[2;37;0m
它是舊夢難溫的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "skyamw");
        set("owner_name", "舊夢難溫");
        set_temp("owner", "skyamw");
        set_temp("owner_name", "舊夢難溫");
        ::setup();
}
