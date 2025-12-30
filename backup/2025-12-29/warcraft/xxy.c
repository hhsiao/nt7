// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小白[2;37;0m[2;37;0m", ({"mmy"}));        
        set("gender", "男性");                
        set("long", "一隻小白虎[2;37;0m
它是大菠蘿的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xxy");
        set("owner_name", "大菠蘿");
        set_temp("owner", "xxy");
        set_temp("owner_name", "大菠蘿");
        ::setup();
}
