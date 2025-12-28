// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m小龍[2;37;0m[2;37;0m", ({"leaflong"}));        
        set("gender", "男性");                
        set("long", "五爪金龍！中國古代龍的群領，是龍族最高的王者，中華圖騰！[2;37;0m
它是葉子龍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "leafl");
        set("owner_name", "葉子龍");
        set_temp("owner", "leafl");
        set_temp("owner_name", "葉子龍");
        ::setup();
}
