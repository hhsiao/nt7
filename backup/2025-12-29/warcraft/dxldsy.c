// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火鳥[2;37;0m[2;37;0m", ({"dsy"}));        
        set("gender", "男性");                
        set("long", "這是一隻全身燃燒著熊熊烈焰的火鳥！[2;37;0m
它是海盜的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dxldsy");
        set("owner_name", "海盜");
        set_temp("owner", "dxldsy");
        set_temp("owner_name", "海盜");
        ::setup();
}
