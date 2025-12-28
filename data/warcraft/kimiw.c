// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "這是武當二號的火麒麟獸，個頭不小。[2;37;0m
它是武當二號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kimiw");
        set("owner_name", "武當二號");
        set_temp("owner", "kimiw");
        set_temp("owner_name", "武當二號");
        ::setup();
}
