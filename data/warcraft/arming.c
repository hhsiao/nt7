// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神獸麒麟[2;37;0m[2;37;0m", ({"qilun"}));        
        set("gender", "男性");                
        set("long", "神獸麒麟出現，眾人趕緊閃吧！[2;37;0m
它是明哥的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "arming");
        set("owner_name", "明哥");
        set_temp("owner", "arming");
        set_temp("owner_name", "明哥");
        ::setup();
}
