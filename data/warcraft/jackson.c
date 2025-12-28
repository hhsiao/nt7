// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m冰[1;35m蠍[2;37;0m[2;37;0m[2;37;0m", ({"jjackson"}));        
        set("gender", "男性");                
        set("long", "冰蠍[2;37;0m
它是怪傑的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jackson");
        set("owner_name", "怪傑");
        set_temp("owner", "jackson");
        set_temp("owner_name", "怪傑");
        ::setup();
}
