// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小香豬[2;37;0m[2;37;0m", ({"xxz"}));        
        set("gender", "男性");                
        set("long", "小香豬[2;37;0m
它是不通神鞭的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "btwhip");
        set("owner_name", "不通神鞭");
        set_temp("owner", "btwhip");
        set_temp("owner_name", "不通神鞭");
        ::setup();
}
