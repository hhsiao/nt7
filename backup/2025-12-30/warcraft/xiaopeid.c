// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "睡袋[2;37;0m
它是花錢的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaopeid");
        set("owner_name", "花錢");
        set_temp("owner", "xiaopeid");
        set_temp("owner_name", "花錢");
        ::setup();
}
