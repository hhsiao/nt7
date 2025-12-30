// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m老烏龜[2;37;0m[2;37;0m", ({"wokao"}));        
        set("gender", "女性");                
        set("long", "不堪一擊的老烏龜[2;37;0m
它是桃美閏的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "luss");
        set("owner_name", "桃美閏");
        set_temp("owner", "luss");
        set_temp("owner_name", "桃美閏");
        ::setup();
}
