// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m赤兔馬[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這就是傳說中的赤兔，渾身火炭般赤紅，龍相虎步、日行萬里。[2;37;0m
它是呂布的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lbu");
        set("owner_name", "呂布");
        set_temp("owner", "lbu");
        set_temp("owner_name", "呂布");
        ::setup();
}
