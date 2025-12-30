// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"lianpet"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是練四的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "liand");
        set("owner_name", "練四");
        set_temp("owner", "liand");
        set_temp("owner_name", "練四");
        ::setup();
}
