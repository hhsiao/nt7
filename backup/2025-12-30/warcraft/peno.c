// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m五[1;35m花[1;36m馬[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "女性");                
        set("long", "$HIW$五$HIM$花$HIC$馬[2;37;0m
它是歐陽詢的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "peno");
        set("owner_name", "歐陽詢");
        set_temp("owner", "peno");
        set_temp("owner_name", "歐陽詢");
        ::setup();
}
