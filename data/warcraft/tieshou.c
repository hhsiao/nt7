// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m一百泥潭幣[2;37;0m[2;37;0m", ({"baintb"}));        
        set("gender", "女性");                
        set("long", "$HIC$一百泥潭幣[2;37;0m
它是何鐵手的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tieshou");
        set("owner_name", "何鐵手");
        set_temp("owner", "tieshou");
        set_temp("owner_name", "何鐵手");
        ::setup();
}
