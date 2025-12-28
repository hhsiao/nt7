// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小兔子[2;37;0m[2;37;0m", ({"rabbit"}));        
        set("gender", "女性");                
        set("long", "肉乎乎的一團[2;37;0m
它是兔子吃肉的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "rubbie");
        set("owner_name", "兔子吃肉");
        set_temp("owner", "rubbie");
        set_temp("owner_name", "兔子吃肉");
        ::setup();
}
