// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;35m強[1;36m盜[2;37;0m[2;37;0m", ({"self"}));        
        set("gender", "女性");                
        set("long", "哦[2;37;0m
它是願藏的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "oneself");
        set("owner_name", "願藏");
        set_temp("owner", "oneself");
        set_temp("owner_name", "願藏");
        ::setup();
}
