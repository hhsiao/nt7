// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("冷靜[2;37;0m[2;37;0m", ({"pingjing"}));        
        set("gender", "男性");                
        set("long", "冷靜[2;37;0m
它是平靜的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "denisd");
        set("owner_name", "平靜");
        set_temp("owner", "denisd");
        set_temp("owner_name", "平靜");
        ::setup();
}
