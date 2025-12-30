// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("契約[2;37;0m[2;37;0m", ({"baifeng"}));        
        set("gender", "女性");                
        set("long", "契約[2;37;0m
它是夏鷗丸的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "felw");
        set("owner_name", "夏鷗丸");
        set_temp("owner", "felw");
        set_temp("owner_name", "夏鷗丸");
        ::setup();
}
