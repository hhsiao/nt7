// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("誰誰誰[2;37;0m[2;37;0m", ({"sheisheishei"}));        
        set("gender", "男性");                
        set("long", "誰誰誰[2;37;0m
它是冷鋒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lengfeng");
        set("owner_name", "冷鋒");
        set_temp("owner", "lengfeng");
        set_temp("owner_name", "冷鋒");
        ::setup();
}
