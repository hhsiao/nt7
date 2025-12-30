// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m馬殺雞[2;37;0m[2;37;0m", ({"hitall"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是殺馬特的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "killall");
        set("owner_name", "殺馬特");
        set_temp("owner", "killall");
        set_temp("owner_name", "殺馬特");
        ::setup();
}
