// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("智慧神獸[2;37;0m[2;37;0m", ({"jinhu"}));        
        set("gender", "男性");                
        set("long", "智慧神獸[2;37;0m
它是武當飛二的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "catb");
        set("owner_name", "武當飛二");
        set_temp("owner", "catb");
        set_temp("owner_name", "武當飛二");
        ::setup();
}
