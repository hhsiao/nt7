// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m鮮紅的鳥兒[2;37;0m[2;37;0m", ({"llll"}));        
        set("gender", "女性");                
        set("long", "因地[2;37;0m
它是練丹神的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lus");
        set("owner_name", "練丹神");
        set_temp("owner", "lus");
        set_temp("owner_name", "練丹神");
        ::setup();
}
