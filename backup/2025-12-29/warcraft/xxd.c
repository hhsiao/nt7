// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("星雲[2;37;0m[2;37;0m", ({"xxdlong"}));        
        set("gender", "女性");                
        set("long", "停權[2;37;0m
它是衛子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xxd");
        set("owner_name", "衛子");
        set_temp("owner", "xxd");
        set_temp("owner_name", "衛子");
        ::setup();
}
