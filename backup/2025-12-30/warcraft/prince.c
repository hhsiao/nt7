// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m金甲[1;31m霸王龍[2;37;0m[2;37;0m", ({"berserk"}));        
        set("gender", "男性");                
        set("long", "暴力王子的坐騎。一頭全身金甲鱗片的巨大霸王龍！[2;37;0m
它是暴力王子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "prince");
        set("owner_name", "暴力王子");
        set_temp("owner", "prince");
        set_temp("owner_name", "暴力王子");
        ::setup();
}
