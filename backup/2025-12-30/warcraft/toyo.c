// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("月影[2;37;0m[2;37;0m", ({"judy"}));        
        set("gender", "女性");                
        set("long", "無[2;37;0m
它是謝雲的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "toyo");
        set("owner_name", "謝雲");
        set_temp("owner", "toyo");
        set_temp("owner_name", "謝雲");
        ::setup();
}
