// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("風中獨行[2;37;0m[2;37;0m", ({"daibu"}));        
        set("gender", "女性");                
        set("long", "人中麒麟[2;37;0m
它是雲裡霧裡的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kokoyc");
        set("owner_name", "雲裡霧裡");
        set_temp("owner", "kokoyc");
        set_temp("owner_name", "雲裡霧裡");
        ::setup();
}
