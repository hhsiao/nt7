// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("太古青龍[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "萬物源頭[2;37;0m
它是糙漢的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "run");
        set("owner_name", "糙漢");
        set_temp("owner", "run");
        set_temp("owner_name", "糙漢");
        ::setup();
}
