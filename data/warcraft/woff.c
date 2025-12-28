// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m楊生黃雀[2;37;0m[2;37;0m", ({"wof"}));        
        set("gender", "男性");                
        set("long", "楊生黃雀!!![2;37;0m
它是夜陸的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "woff");
        set("owner_name", "夜陸");
        set_temp("owner", "woff");
        set_temp("owner_name", "夜陸");
        ::setup();
}
