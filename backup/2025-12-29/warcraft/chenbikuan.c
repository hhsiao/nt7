// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("嘯易今夕[2;37;0m[2;37;0m", ({"chen_chong"}));        
        set("gender", "男性");                
        set("long", "通體碧綠，其身鱗片閃閃發亮，一吼[2;37;0m
它是遙劍沂笑的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "chenbikuan");
        set("owner_name", "遙劍沂笑");
        set_temp("owner", "chenbikuan");
        set_temp("owner_name", "遙劍沂笑");
        ::setup();
}
