// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小眼[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "小眼[2;37;0m
它是黑鋼飛刀的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nnu");
        set("owner_name", "黑鋼飛刀");
        set_temp("owner", "nnu");
        set_temp("owner_name", "黑鋼飛刀");
        ::setup();
}
