// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m聖獸玄武[2;37;0m[2;37;0m", ({"xuanwu"}));        
        set("gender", "男性");                
        set("long", "這是楊老大的寵物-聖獸玄武[2;37;0m
它是楊泥巴的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "yangnt");
        set("owner_name", "楊泥巴");
        set_temp("owner", "yangnt");
        set_temp("owner_name", "楊泥巴");
        ::setup();
}
