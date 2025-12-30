// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("遠古神獸[2;37;0m[2;37;0m", ({"qianwang"}));        
        set("gender", "男性");                
        set("long", "遠古神獸[2;37;0m
它是長虹的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "changhong");
        set("owner_name", "長虹");
        set_temp("owner", "changhong");
        set_temp("owner_name", "長虹");
        ::setup();
}
