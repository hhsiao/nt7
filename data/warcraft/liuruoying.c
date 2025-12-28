// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m為愛痴狂[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "男性");                
        set("long", "我愛我的龍龍[2;37;0m
它是劉若英的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "liuruoying");
        set("owner_name", "劉若英");
        set_temp("owner", "liuruoying");
        set_temp("owner_name", "劉若英");
        ::setup();
}
