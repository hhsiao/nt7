// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小香豬[2;37;0m[2;37;0m", ({"xxz"}));        
        set("gender", "男性");                
        set("long", "小香豬[2;37;0m
它是不通鞋仔的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "btboots");
        set("owner_name", "不通鞋仔");
        set_temp("owner", "btboots");
        set_temp("owner_name", "不通鞋仔");
        ::setup();
}
