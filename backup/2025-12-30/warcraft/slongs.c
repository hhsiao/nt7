// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m神獸[2;37;0m[2;37;0m[2;37;0m", ({"lijie"}));        
        set("gender", "男性");                
        set("long", "無[2;37;0m
它是冰洋凝眸的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "slongs");
        set("owner_name", "冰洋凝眸");
        set_temp("owner", "slongs");
        set_temp("owner_name", "冰洋凝眸");
        ::setup();
}
