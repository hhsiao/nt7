// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "巨大的白虎[2;37;0m
它是軒轅九天的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "jiutian");
        set("owner_name", "軒轅九天");
        set_temp("owner", "jiutian");
        set_temp("owner_name", "軒轅九天");
        ::setup();
}
