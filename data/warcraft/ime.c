// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m小馬駒[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "$小馬駒[2;37;0m
它是莫沫沫的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ime");
        set("owner_name", "莫沫沫");
        set_temp("owner", "ime");
        set_temp("owner_name", "莫沫沫");
        ::setup();
}
