// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火麒麟[2;37;0m[2;37;0m", ({"hql"}));        
        set("gender", "男性");                
        set("long", "這是十龍十象的火麒麟。[2;37;0m
它是十龍十象的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yanglx");
        set("owner_name", "十龍十象");
        set_temp("owner", "yanglx");
        set_temp("owner_name", "十龍十象");
        ::setup();
}
