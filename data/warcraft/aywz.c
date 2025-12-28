// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小白[2;37;0m[2;37;0m", ({"xiaobai"}));        
        set("gender", "男性");                
        set("long", "好吃懶做[2;37;0m
它是諸葛瑾的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "aywz");
        set("owner_name", "諸葛瑾");
        set_temp("owner", "aywz");
        set_temp("owner_name", "諸葛瑾");
        ::setup();
}
