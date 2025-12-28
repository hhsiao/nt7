// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m浴火重生[2;37;0m[2;37;0m", ({"qwe"}));        
        set("gender", "男性");                
        set("long", "SHIT[2;37;0m
它是小強子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "strong");
        set("owner_name", "小強子");
        set_temp("owner", "strong");
        set_temp("owner_name", "小強子");
        ::setup();
}
