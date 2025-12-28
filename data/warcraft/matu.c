// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m壹黃[2;37;0m[2;37;0m", ({"matupet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是黃壹的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matu");
        set("owner_name", "黃壹");
        set_temp("owner", "matu");
        set_temp("owner_name", "黃壹");
        ::setup();
}
