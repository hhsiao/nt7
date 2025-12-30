// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啾啾擠擠[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "更好非結構化[2;37;0m
它是清神開孔的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mxu");
        set("owner_name", "清神開孔");
        set_temp("owner", "mxu");
        set_temp("owner_name", "清神開孔");
        ::setup();
}
