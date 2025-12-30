// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("先鋒[2;37;0m[2;37;0m", ({"xiaodamii"}));        
        set("gender", "男性");                
        set("long", "先鋒[2;37;0m
它是探路先鋒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaodami");
        set("owner_name", "探路先鋒");
        set_temp("owner", "xiaodami");
        set_temp("owner_name", "探路先鋒");
        ::setup();
}
