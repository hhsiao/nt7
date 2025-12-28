// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("殘影[2;37;0m[2;37;0m", ({"monster"}));        
        set("gender", "男性");                
        set("long", "小乖乖[2;37;0m
它是阿財的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "choo");
        set("owner_name", "阿財");
        set_temp("owner", "choo");
        set_temp("owner_name", "阿財");
        ::setup();
}
