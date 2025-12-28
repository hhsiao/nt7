// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("赫拉克勒斯[2;37;0m[2;37;0m", ({"axx"}));        
        set("gender", "男性");                
        set("long", "sada[2;37;0m
它是燃料循環的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "thonium");
        set("owner_name", "燃料循環");
        set_temp("owner", "thonium");
        set_temp("owner_name", "燃料循環");
        ::setup();
}
