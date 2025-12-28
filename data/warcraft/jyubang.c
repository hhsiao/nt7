// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("幫居於[2;37;0m[2;37;0m", ({"bangjyu"}));        
        set("gender", "女性");                
        set("long", "幫居於[2;37;0m
它是居於幫的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jyubang");
        set("owner_name", "居於幫");
        set_temp("owner", "jyubang");
        set_temp("owner_name", "居於幫");
        ::setup();
}
