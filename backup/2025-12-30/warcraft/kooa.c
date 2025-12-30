// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m人力三輪[2;37;0m[2;37;0m", ({"aoo"}));        
        set("gender", "女性");                
        set("long", "$HIW$人力三輪[2;37;0m
它是鄉巴佬的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kooa");
        set("owner_name", "鄉巴佬");
        set_temp("owner", "kooa");
        set_temp("owner_name", "鄉巴佬");
        ::setup();
}
