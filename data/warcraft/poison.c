// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m玄冰寒毒[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "sleep[2;37;0m
它是毒藥的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "poison");
        set("owner_name", "毒藥");
        set_temp("owner", "poison");
        set_temp("owner_name", "毒藥");
        ::setup();
}
