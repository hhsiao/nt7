// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m試當武[2;37;0m[2;37;0m", ({"wdtestaa"}));        
        set("gender", "男性");                
        set("long", "阿[2;37;0m
它是武當試的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wdtesta");
        set("owner_name", "武當試");
        set_temp("owner", "wdtesta");
        set_temp("owner_name", "武當試");
        ::setup();
}
