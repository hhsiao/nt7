// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("貓[2;37;0m[2;37;0m", ({"mao"}));        
        set("gender", "女性");                
        set("long", "一隻小貓[2;37;0m
它是綺伊的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "qiyi");
        set("owner_name", "綺伊");
        set_temp("owner", "qiyi");
        set_temp("owner_name", "綺伊");
        ::setup();
}
