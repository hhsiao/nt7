// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"caca"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是扁鵲的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bianque");
        set("owner_name", "扁鵲");
        set_temp("owner", "bianque");
        set_temp("owner_name", "扁鵲");
        ::setup();
}
