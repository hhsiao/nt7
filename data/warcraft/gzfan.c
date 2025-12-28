// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("好煩[2;37;0m[2;37;0m", ({"haofan"}));        
        set("gender", "男性");                
        set("long", "垃圾國足[2;37;0m
它是國足煩的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gzfan");
        set("owner_name", "國足煩");
        set_temp("owner", "gzfan");
        set_temp("owner_name", "國足煩");
        ::setup();
}
