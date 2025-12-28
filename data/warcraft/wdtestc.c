// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m品當武[2;37;0m[2;37;0m", ({"wdtestcc"}));        
        set("gender", "男性");                
        set("long", "阿[2;37;0m
它是武當品的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wdtestc");
        set("owner_name", "武當品");
        set_temp("owner", "wdtestc");
        set_temp("owner_name", "武當品");
        ::setup();
}
