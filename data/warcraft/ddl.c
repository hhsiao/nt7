// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"ddll"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是堂來的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ddl");
        set("owner_name", "堂來");
        set_temp("owner", "ddl");
        set_temp("owner_name", "堂來");
        ::setup();
}
