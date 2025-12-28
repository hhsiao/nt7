// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雲心[2;37;0m[2;37;0m", ({"tofly"}));        
        set("gender", "男性");                
        set("long", "無[2;37;0m
它是獨孤雲的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yumio");
        set("owner_name", "獨孤雲");
        set_temp("owner", "yumio");
        set_temp("owner_name", "獨孤雲");
        ::setup();
}
