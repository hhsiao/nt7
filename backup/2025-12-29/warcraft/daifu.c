// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大飛龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "一隻器宇軒昂的大飛龍[2;37;0m
它是大夫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "daifu");
        set("owner_name", "大夫");
        set_temp("owner", "daifu");
        set_temp("owner_name", "大夫");
        ::setup();
}
