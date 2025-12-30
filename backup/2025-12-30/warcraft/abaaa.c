// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m毛驢[2;37;0m[2;37;0m", ({"maolv"}));        
        set("gender", "女性");                
        set("long", "毛驢[2;37;0m
它是苦力一號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "abaaa");
        set("owner_name", "苦力一號");
        set_temp("owner", "abaaa");
        set_temp("owner_name", "苦力一號");
        ::setup();
}
