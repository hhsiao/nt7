// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地圖精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "23456[2;37;0m
它是蒼月空的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "nsli");
        set("owner_name", "蒼月空");
        set_temp("owner", "nsli");
        set_temp("owner_name", "蒼月空");
        ::setup();
}
