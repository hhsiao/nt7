// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m應[1;37m龍[2;37;0m[2;37;0m", ({"ioi"}));        
        set("gender", "男性");                
        set("long", "旱而為應龍之狀，乃得大雨。目開而日出，目閉而日落[2;37;0m
它是馬瑪的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ohmm");
        set("owner_name", "馬瑪");
        set_temp("owner", "ohmm");
        set_temp("owner_name", "馬瑪");
        ::setup();
}
