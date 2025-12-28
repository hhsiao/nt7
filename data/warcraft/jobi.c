// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m鋼鐵裝甲[2;37;0m[2;37;0m", ({"tank"}));        
        set("gender", "男性");                
        set("long", "鋼鐵裝甲[2;37;0m
它是打工二號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jobi");
        set("owner_name", "打工二號");
        set_temp("owner", "jobi");
        set_temp("owner_name", "打工二號");
        ::setup();
}
