// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("星雲[2;37;0m[2;37;0m", ({"xingda"}));        
        set("gender", "男性");                
        set("long", "星雲[2;37;0m
它是星雲二的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xingd");
        set("owner_name", "星雲二");
        set_temp("owner", "xingd");
        set_temp("owner_name", "星雲二");
        ::setup();
}
