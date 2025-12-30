// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m紅蓮道人[2;37;0m[2;37;0m", ({"rod"}));        
        set("gender", "男性");                
        set("long", "$HIR$紅蓮道人[2;37;0m
它是當歸的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "danggui");
        set("owner_name", "當歸");
        set_temp("owner", "danggui");
        set_temp("owner_name", "當歸");
        ::setup();
}
