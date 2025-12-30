// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m飛韻[2;37;0m[2;37;0m", ({"mimi"}));        
        set("gender", "女性");                
        set("long", "有點可愛，有點萌[2;37;0m
它是南宮萍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ngp");
        set("owner_name", "南宮萍");
        set_temp("owner", "ngp");
        set_temp("owner_name", "南宮萍");
        ::setup();
}
