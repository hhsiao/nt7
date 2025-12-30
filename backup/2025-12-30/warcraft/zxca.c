// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m壹錢[2;37;0m[2;37;0m", ({"zxcapet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是錢壹的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxca");
        set("owner_name", "錢壹");
        set_temp("owner", "zxca");
        set_temp("owner_name", "錢壹");
        ::setup();
}
