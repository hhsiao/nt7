// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟獸[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "一隻小小的麒麟獸[2;37;0m
它是小馬哥哥的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "majun");
        set("owner_name", "小馬哥哥");
        set_temp("owner", "majun");
        set_temp("owner_name", "小馬哥哥");
        ::setup();
}
