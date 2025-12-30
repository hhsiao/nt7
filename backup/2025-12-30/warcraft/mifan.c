// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小紅米[2;37;0m[2;37;0m", ({"xmi"}));        
        set("gender", "男性");                
        set("long", "小紅米[2;37;0m
它是白米飯的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mifan");
        set("owner_name", "白米飯");
        set_temp("owner", "mifan");
        set_temp("owner_name", "白米飯");
        ::setup();
}
