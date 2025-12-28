// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m青龍[2;37;0m[2;37;0m", ({"spk"}));        
        set("gender", "女性");                
        set("long", "finish[2;37;0m
它是天誅的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sunpk");
        set("owner_name", "天誅");
        set_temp("owner", "sunpk");
        set_temp("owner_name", "天誅");
        ::setup();
}
