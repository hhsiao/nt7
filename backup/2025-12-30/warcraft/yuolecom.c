// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("加顏[2;37;0m[2;37;0m", ({"feifeihou"}));        
        set("gender", "男性");                
        set("long", "加顏[2;37;0m
它是張譽的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yuolecom");
        set("owner_name", "張譽");
        set_temp("owner", "yuolecom");
        set_temp("owner_name", "張譽");
        ::setup();
}
