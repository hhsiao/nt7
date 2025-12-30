// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m青龍[2;37;0m[2;37;0m", ({"qlong"}));        
        set("gender", "男性");                
        set("long", "神獸[2;37;0m
它是阿三的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dmccc");
        set("owner_name", "阿三");
        set_temp("owner", "dmccc");
        set_temp("owner_name", "阿三");
        ::setup();
}
