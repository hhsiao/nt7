// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("究極進化[2;37;0m[2;37;0m", ({"jinhu"}));        
        set("gender", "男性");                
        set("long", "究極進化[2;37;0m
它是武當飛一的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cata");
        set("owner_name", "武當飛一");
        set_temp("owner", "cata");
        set_temp("owner_name", "武當飛一");
        ::setup();
}
