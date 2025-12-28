// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m泡泡龍[2;37;0m[2;37;0m", ({"paopao"}));        
        set("gender", "女性");                
        set("long", "$HIM$泡泡龍[2;37;0m
它是隨心的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lskx");
        set("owner_name", "隨心");
        set_temp("owner", "lskx");
        set_temp("owner_name", "隨心");
        ::setup();
}
