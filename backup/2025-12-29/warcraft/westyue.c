// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("月之土[2;37;0m[2;37;0m", ({"moontutu"}));        
        set("gender", "女性");                
        set("long", "月之土[2;37;0m
它是西語的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "westyue");
        set("owner_name", "西語");
        set_temp("owner", "westyue");
        set_temp("owner_name", "西語");
        ::setup();
}
