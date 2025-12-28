// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m小紅[2;37;0m[2;37;0m", ({"wuya"}));        
        set("gender", "女性");                
        set("long", "一隻紅色的小鳥[2;37;0m
它是烏丫的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "uya");
        set("owner_name", "烏丫");
        set_temp("owner", "uya");
        set_temp("owner_name", "烏丫");
        ::setup();
}
