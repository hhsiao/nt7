// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m一億[2;37;0m[2;37;0m", ({"yua"}));        
        set("gender", "男性");                
        set("long", "就是人民幣[2;37;0m
它是空密的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jsatb");
        set("owner_name", "空密");
        set_temp("owner", "jsatb");
        set_temp("owner_name", "空密");
        ::setup();
}
