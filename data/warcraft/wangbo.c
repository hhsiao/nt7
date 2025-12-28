// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m畫棟朝飛[2;37;0m[2;37;0m", ({"zian"}));        
        set("gender", "男性");                
        set("long", "閒雲潭影日悠悠，物換星移幾度秋[2;37;0m
它是王勃的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wangbo");
        set("owner_name", "王勃");
        set_temp("owner", "wangbo");
        set_temp("owner_name", "王勃");
        ::setup();
}
