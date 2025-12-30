// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("筋斗雲[2;37;0m[2;37;0m", ({"jdy"}));        
        set("gender", "男性");                
        set("long", "筋斗雲[2;37;0m
它是美不勝收的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "skyami");
        set("owner_name", "美不勝收");
        set_temp("owner", "skyami");
        set_temp("owner_name", "美不勝收");
        ::setup();
}
