// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m化血朱雀[2;37;0m[2;37;0m", ({"qmgg"}));        
        set("gender", "女性");                
        set("long", "化血朱雀[2;37;0m
它是星宿清風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qmg");
        set("owner_name", "星宿清風");
        set_temp("owner", "qmg");
        set_temp("owner_name", "星宿清風");
        ::setup();
}
