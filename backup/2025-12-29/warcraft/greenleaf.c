// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m騎馬舞[2;37;0m[2;37;0m", ({"greenpet"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是綠葉的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "greenleaf");
        set("owner_name", "綠葉");
        set_temp("owner", "greenleaf");
        set_temp("owner_name", "綠葉");
        ::setup();
}
