// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("遊無窮[2;37;0m[2;37;0m", ({"tofly"}));        
        set("gender", "女性");                
        set("long", "飛[2;37;0m
它是謝風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "togo");
        set("owner_name", "謝風");
        set_temp("owner", "togo");
        set_temp("owner_name", "謝風");
        ::setup();
}
