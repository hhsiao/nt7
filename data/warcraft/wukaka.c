// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m低調[2;37;0m[2;37;0m", ({"wukakaride"}));        
        set("gender", "男性");                
        set("long", "$HIC$低調[2;37;0m
它是白眉道長的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wukaka");
        set("owner_name", "白眉道長");
        set_temp("owner", "wukaka");
        set_temp("owner_name", "白眉道長");
        ::setup();
}
