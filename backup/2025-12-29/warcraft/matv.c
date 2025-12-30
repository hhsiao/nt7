// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m貳黃[2;37;0m[2;37;0m", ({"matvpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是黃貳的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matv");
        set("owner_name", "黃貳");
        set_temp("owner", "matv");
        set_temp("owner_name", "黃貳");
        ::setup();
}
