// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("別看我對眼[2;37;0m[2;37;0m", ({"biudi"}));        
        set("gender", "男性");                
        set("long", "我發起火來連自己都打[2;37;0m
它是寶慶金樓的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "gkytail");
        set("owner_name", "寶慶金樓");
        set_temp("owner", "gkytail");
        set_temp("owner_name", "寶慶金樓");
        ::setup();
}
