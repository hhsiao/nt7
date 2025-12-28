// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馴鹿[2;37;0m[2;37;0m", ({"baoma"}));        
        set("gender", "男性");                
        set("long", "馴鹿[2;37;0m
它是九劍孤獨的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hstguiji");
        set("owner_name", "九劍孤獨");
        set_temp("owner", "hstguiji");
        set_temp("owner_name", "九劍孤獨");
        ::setup();
}
