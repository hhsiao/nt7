// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("電動車[2;37;0m[2;37;0m", ({"fox"}));        
        set("gender", "女性");                
        set("long", "電動車[2;37;0m
它是不二熊的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "colorwol");
        set("owner_name", "不二熊");
        set_temp("owner", "colorwol");
        set_temp("owner_name", "不二熊");
        ::setup();
}
