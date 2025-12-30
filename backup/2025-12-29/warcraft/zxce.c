// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m伍錢[2;37;0m[2;37;0m", ({"zxcepet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是錢伍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxce");
        set("owner_name", "錢伍");
        set_temp("owner", "zxce");
        set_temp("owner_name", "錢伍");
        ::setup();
}
