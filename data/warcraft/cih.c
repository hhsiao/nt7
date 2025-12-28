// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m瑞獸[2;37;0m[2;37;0m", ({"gyill"}));        
        set("gender", "男性");                
        set("long", "無[2;37;0m
它是眼總的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cih");
        set("owner_name", "眼總");
        set_temp("owner", "cih");
        set_temp("owner_name", "眼總");
        ::setup();
}
