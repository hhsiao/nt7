// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m青天獸[2;37;0m[2;37;0m", ({"kinggmshou"}));        
        set("gender", "男性");                
        set("long", "四大神獸[2;37;0m
它是冰淇淋的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kinggm");
        set("owner_name", "冰淇淋");
        set_temp("owner", "kinggm");
        set_temp("owner_name", "冰淇淋");
        ::setup();
}
