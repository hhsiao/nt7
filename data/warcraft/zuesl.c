// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m理論[2;37;0m[2;37;0m", ({"zuesls"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是賊就的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zuesl");
        set("owner_name", "賊就");
        set_temp("owner", "zuesl");
        set_temp("owner_name", "賊就");
        ::setup();
}
