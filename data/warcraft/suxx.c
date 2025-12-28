// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m小曉[2;37;0m[2;37;0m", ({"suxxs"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是蘇小曉的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "suxx");
        set("owner_name", "蘇小曉");
        set_temp("owner", "suxx");
        set_temp("owner_name", "蘇小曉");
        ::setup();
}
