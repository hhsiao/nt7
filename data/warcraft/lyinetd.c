// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m鳳舞九條[2;37;0m[2;37;0m", ({"piple"}));        
        set("gender", "女性");                
        set("long", "鳳舞九天[2;37;0m
它是小小的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lyinetd");
        set("owner_name", "小小");
        set_temp("owner", "lyinetd");
        set_temp("owner_name", "小小");
        ::setup();
}
