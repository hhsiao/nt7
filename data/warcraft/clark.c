// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("淑玲[2;37;0m[2;37;0m", ({"suling"}));        
        set("gender", "女性");                
        set("long", "黑心女人[2;37;0m
它是時鐘的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "clark");
        set("owner_name", "時鐘");
        set_temp("owner", "clark");
        set_temp("owner_name", "時鐘");
        ::setup();
}
