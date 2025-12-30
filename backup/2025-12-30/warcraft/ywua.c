// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m驢子他爹[2;37;0m[2;37;0m", ({"lvzia"}));        
        set("gender", "男性");                
        set("long", "驢子他爹[2;37;0m
它是邪月禿賊的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ywua");
        set("owner_name", "邪月禿賊");
        set_temp("owner", "ywua");
        set_temp("owner_name", "邪月禿賊");
        ::setup();
}
