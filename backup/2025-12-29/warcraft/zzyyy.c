// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m[5m赤炎[2;37;0m[2;37;0m", ({"ync"}));        
        set("gender", "男性");                
        set("long", "天外飛來一團熾熱的火球，席捲著整個神州大地[2;37;0m
它是煙鬼的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zzyyy");
        set("owner_name", "煙鬼");
        set_temp("owner", "zzyyy");
        set_temp("owner_name", "煙鬼");
        ::setup();
}
