// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m老母雞[2;37;0m[2;37;0m", ({"hen"}));        
        set("gender", "女性");                
        set("long", "沒[2;37;0m
它是乙打雜的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ipxb");
        set("owner_name", "乙打雜");
        set_temp("owner", "ipxb");
        set_temp("owner_name", "乙打雜");
        ::setup();
}
