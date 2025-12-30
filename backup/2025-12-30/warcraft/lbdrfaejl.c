// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"west"}));        
        set("gender", "女性");                
        set("long", "do 自行車,自行車[2;37;0m
它是卓灝玉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lbdrfaejl");
        set("owner_name", "卓灝玉");
        set_temp("owner", "lbdrfaejl");
        set_temp("owner_name", "卓灝玉");
        ::setup();
}
