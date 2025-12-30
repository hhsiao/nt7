// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"nbzhpet"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是泥巴字號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nbzh");
        set("owner_name", "泥巴字號");
        set_temp("owner", "nbzh");
        set_temp("owner_name", "泥巴字號");
        ::setup();
}
