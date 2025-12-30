// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m語嫣[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "女性");                
        set("long", "$HIM$語嫣[2;37;0m
它是參透的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kkarby");
        set("owner_name", "參透");
        set_temp("owner", "kkarby");
        set_temp("owner_name", "參透");
        ::setup();
}
