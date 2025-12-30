// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m子彈[2;37;0m[2;37;0m", ({"sudu"}));        
        set("gender", "男性");                
        set("long", "速度無止盡[2;37;0m
它是火雲邪神的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "speed");
        set("owner_name", "火雲邪神");
        set_temp("owner", "speed");
        set_temp("owner_name", "火雲邪神");
        ::setup();
}
