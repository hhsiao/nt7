// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m神鳥鳳凰[2;37;0m[2;37;0m", ({"mim"}));        
        set("gender", "女性");                
        set("long", "百鳥之王，烈火重生[2;37;0m
它是龍布寺的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "longbu");
        set("owner_name", "龍布寺");
        set_temp("owner", "longbu");
        set_temp("owner_name", "龍布寺");
        ::setup();
}
