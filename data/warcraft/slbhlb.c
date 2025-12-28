// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m航空母艦[2;37;0m[2;37;0m", ({"niao"}));        
        set("gender", "女性");                
        set("long", "航空母艦[2;37;0m
它是峰峰的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "slbhlb");
        set("owner_name", "峰峰");
        set_temp("owner", "slbhlb");
        set_temp("owner_name", "峰峰");
        ::setup();
}
