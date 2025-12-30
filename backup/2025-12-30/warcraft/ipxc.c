// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m大公雞[2;37;0m[2;37;0m", ({"cock"}));        
        set("gender", "女性");                
        set("long", "沒[2;37;0m
它是丙打雜的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ipxc");
        set("owner_name", "丙打雜");
        set_temp("owner", "ipxc");
        set_temp("owner_name", "丙打雜");
        ::setup();
}
