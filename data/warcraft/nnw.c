// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小眼[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "小眼[2;37;0m
它是愛過後的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nnw");
        set("owner_name", "愛過後");
        set_temp("owner", "nnw");
        set_temp("owner_name", "愛過後");
        ::setup();
}
