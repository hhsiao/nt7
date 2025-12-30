// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("藍鳥[2;37;0m[2;37;0m", ({"lanniao"}));        
        set("gender", "女性");                
        set("long", "藍鳥[2;37;0m
它是許可的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "danshui");
        set("owner_name", "許可");
        set_temp("owner", "danshui");
        set_temp("owner_name", "許可");
        ::setup();
}
