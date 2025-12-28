// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[44;1m[1;36m太古[1;33m麒麟[1;31m聖皇[2;37;0m[2;37;0m", ({"antediluvian"}));        
        set("gender", "男性");                
        set("long", "太古時代麒麟一族的聖皇。它全身覆蓋著厚實的鱗甲發出金色聖光。[2;37;0m
它是龍麟霸天的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ron");
        set("owner_name", "龍麟霸天");
        set_temp("owner", "ron");
        set_temp("owner_name", "龍麟霸天");
        ::setup();
}
