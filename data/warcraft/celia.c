// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小貓貓[2;37;0m[2;37;0m", ({"ccmao"}));        
        set("gender", "女性");                
        set("long", "小貓貓[2;37;0m
它是龍美美的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "celia");
        set("owner_name", "龍美美");
        set_temp("owner", "celia");
        set_temp("owner_name", "龍美美");
        ::setup();
}
