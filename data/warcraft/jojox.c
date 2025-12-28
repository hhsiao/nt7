// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m小跟班[2;37;0m[2;37;0m", ({"dtdg"}));        
        set("gender", "男性");                
        set("long", "帶頭大哥的小跟班。[2;37;0m
它是帶頭大哥的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jojox");
        set("owner_name", "帶頭大哥");
        set_temp("owner", "jojox");
        set_temp("owner_name", "帶頭大哥");
        ::setup();
}
