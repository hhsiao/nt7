// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "一頭周身通體冒著火光火麒麟[2;37;0m
它是名劍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mingjian");
        set("owner_name", "名劍");
        set_temp("owner", "mingjian");
        set_temp("owner_name", "名劍");
        ::setup();
}
