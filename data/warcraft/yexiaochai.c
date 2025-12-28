// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("刀狂劍痴[2;37;0m[2;37;0m", ({"daokuang"}));        
        set("gender", "男性");                
        set("long", "刀狂劍痴[2;37;0m
它是葉小釵的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yexiaochai");
        set("owner_name", "葉小釵");
        set_temp("owner", "yexiaochai");
        set_temp("owner_name", "葉小釵");
        ::setup();
}
