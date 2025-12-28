// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啾啾擠擠[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "更好非結構化[2;37;0m
它是就砍會計的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mxx");
        set("owner_name", "就砍會計");
        set_temp("owner", "mxx");
        set_temp("owner_name", "就砍會計");
        ::setup();
}
