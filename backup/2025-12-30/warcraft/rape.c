// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m[5m快[1;32m[5m來[2;37;0m[2;37;0m", ({"mypet"}));        
        set("gender", "女性");                
        set("long", "快來[2;37;0m
它是女乾的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "rape");
        set("owner_name", "女幹");
        set_temp("owner", "rape");
        set_temp("owner_name", "女幹");
        ::setup();
}
