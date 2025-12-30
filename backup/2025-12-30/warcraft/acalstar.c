// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("餘小獸[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "我的小麒麟[2;37;0m
它是餘青風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "acalstar");
        set("owner_name", "餘青風");
        set_temp("owner", "acalstar");
        set_temp("owner_name", "餘青風");
        ::setup();
}
