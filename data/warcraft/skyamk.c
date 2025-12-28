// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("筋斗雲[2;37;0m[2;37;0m", ({"jdy"}));        
        set("gender", "男性");                
        set("long", "筋斗雲[2;37;0m
它是東隅已逝的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "skyamk");
        set("owner_name", "東隅已逝");
        set_temp("owner", "skyamk");
        set_temp("owner_name", "東隅已逝");
        ::setup();
}
