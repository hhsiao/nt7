// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小眼[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "小眼[2;37;0m
它是起來著啊的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nni");
        set("owner_name", "起來著啊");
        set_temp("owner", "nni");
        set_temp("owner_name", "起來著啊");
        ::setup();
}
