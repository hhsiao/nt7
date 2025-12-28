// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小青龍[2;37;0m[2;37;0m", ({"xql"}));        
        set("gender", "男性");                
        set("long", "我是一條小青龍。[2;37;0m
它是歐陽一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gka");
        set("owner_name", "歐陽一");
        set_temp("owner", "gka");
        set_temp("owner_name", "歐陽一");
        ::setup();
}
