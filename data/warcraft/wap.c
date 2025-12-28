// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("草泥馬[2;37;0m[2;37;0m", ({"fuck"}));        
        set("gender", "男性");                
        set("long", "神獸[2;37;0m
它是電網費電的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wap");
        set("owner_name", "電網費電");
        set_temp("owner", "wap");
        set_temp("owner_name", "電網費電");
        ::setup();
}
