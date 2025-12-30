// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大[2;37;0m[2;37;0m", ({"big"}));        
        set("gender", "男性");                
        set("long", "頭[2;37;0m
它是蕭鷂子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xyz");
        set("owner_name", "蕭鷂子");
        set_temp("owner", "xyz");
        set_temp("owner_name", "蕭鷂子");
        ::setup();
}
