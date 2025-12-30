// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[34m藍鳥[2;37;0m[2;37;0m", ({"redbird"}));        
        set("gender", "女性");                
        set("long", "藍鳥[2;37;0m
它是樂藍的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "honor");
        set("owner_name", "樂藍");
        set_temp("owner", "honor");
        set_temp("owner_name", "樂藍");
        ::setup();
}
