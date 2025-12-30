// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("讀書獸[2;37;0m[2;37;0m", ({"getbookride"}));        
        set("gender", "男性");                
        set("long", "讀書獸[2;37;0m
它是拿書的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "getbook");
        set("owner_name", "拿書");
        set_temp("owner", "getbook");
        set_temp("owner_name", "拿書");
        ::setup();
}
