// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("低調[2;37;0m[2;37;0m", ({"auxf"}));        
        set("gender", "女性");                
        set("long", "非常的。。。低調[2;37;0m
它是燙爬追魂的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "csj");
        set("owner_name", "燙爬追魂");
        set_temp("owner", "csj");
        set_temp("owner_name", "燙爬追魂");
        ::setup();
}
