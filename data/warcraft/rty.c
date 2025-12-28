// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("彩雲[2;37;0m[2;37;0m", ({"judy"}));        
        set("gender", "女性");                
        set("long", "無[2;37;0m
它是雲依的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "rty");
        set("owner_name", "雲依");
        set_temp("owner", "rty");
        set_temp("owner_name", "雲依");
        ::setup();
}
