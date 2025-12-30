// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("火鳳凰[2;37;0m[2;37;0m", ({"huofeng"}));        
        set("gender", "女性");                
        set("long", "全身火紅的動物[2;37;0m
它是冰兒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "binger");
        set("owner_name", "冰兒");
        set_temp("owner", "binger");
        set_temp("owner_name", "冰兒");
        ::setup();
}
