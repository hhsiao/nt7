// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙鳥[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "女性");                
        set("long", "神仙鳥[2;37;0m
它是龍風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "longfengd");
        set("owner_name", "龍風");
        set_temp("owner", "longfengd");
        set_temp("owner_name", "龍風");
        ::setup();
}
