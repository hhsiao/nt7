// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m喜鵲[2;37;0m[2;37;0m", ({"xique"}));        
        set("gender", "女性");                
        set("long", "$HIR$喜鵲[2;37;0m
它是織女的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zhinv");
        set("owner_name", "織女");
        set_temp("owner", "zhinv");
        set_temp("owner_name", "織女");
        ::setup();
}
