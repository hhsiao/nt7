// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("筋斗雲[2;37;0m[2;37;0m", ({"jdy"}));        
        set("gender", "男性");                
        set("long", "筋斗雲[2;37;0m
它是兩情相悅的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "skyamt");
        set("owner_name", "兩情相悅");
        set_temp("owner", "skyamt");
        set_temp("owner_name", "兩情相悅");
        ::setup();
}
