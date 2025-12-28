// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是史詩巨獸的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "avc");
        set("owner_name", "史詩巨獸");
        set_temp("owner", "avc");
        set_temp("owner_name", "史詩巨獸");
        ::setup();
}
