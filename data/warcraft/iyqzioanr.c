// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是雍英帆的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "iyqzioanr");
        set("owner_name", "雍英帆");
        set_temp("owner", "iyqzioanr");
        set_temp("owner_name", "雍英帆");
        ::setup();
}
