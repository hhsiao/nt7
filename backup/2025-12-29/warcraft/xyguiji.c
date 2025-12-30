// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大海龜[2;37;0m[2;37;0m", ({"baoma"}));        
        set("gender", "男性");                
        set("long", "大海龜[2;37;0m
它是沒商聖龍的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "xyguiji");
        set("owner_name", "沒商聖龍");
        set_temp("owner", "xyguiji");
        set_temp("owner_name", "沒商聖龍");
        ::setup();
}
