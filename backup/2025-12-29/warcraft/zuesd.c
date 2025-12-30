// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37;41m滴滴[2;37;0m[2;37;0m", ({"zuesds"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是葉四的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zuesd");
        set("owner_name", "葉四");
        set_temp("owner", "zuesd");
        set_temp("owner_name", "葉四");
        ::setup();
}
