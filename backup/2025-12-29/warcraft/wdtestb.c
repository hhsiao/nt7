// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m驗當武[2;37;0m[2;37;0m", ({"westtestbb"}));        
        set("gender", "男性");                
        set("long", "阿[2;37;0m
它是武當驗的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wdtestb");
        set("owner_name", "武當驗");
        set_temp("owner", "wdtestb");
        set_temp("owner_name", "武當驗");
        ::setup();
}
