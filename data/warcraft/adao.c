// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m九天白鶴[2;37;0m[2;37;0m", ({"bird"}));        
        set("gender", "女性");                
        set("long", "遠古飛來的仙鶴。[2;37;0m
它是一個道士的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "adao");
        set("owner_name", "一個道士");
        set_temp("owner", "adao");
        set_temp("owner_name", "一個道士");
        ::setup();
}
