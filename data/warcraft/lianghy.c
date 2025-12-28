// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m紅玉[2;37;0m[2;37;0m", ({"lianghys"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是梁紅玉的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lianghy");
        set("owner_name", "梁紅玉");
        set_temp("owner", "lianghy");
        set_temp("owner_name", "梁紅玉");
        ::setup();
}
