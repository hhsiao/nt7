// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m一道槓[2;37;0m[2;37;0m", ({"daoyi"}));        
        set("gender", "男性");                
        set("long", "槓上開花[2;37;0m
它是一念之差的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dangyi");
        set("owner_name", "一念之差");
        set_temp("owner", "dangyi");
        set_temp("owner_name", "一念之差");
        ::setup();
}
