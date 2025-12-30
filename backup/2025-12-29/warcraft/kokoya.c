// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大眾[2;37;0m[2;37;0m", ({"daibu"}));        
        set("gender", "女性");                
        set("long", "好車[2;37;0m
它是難得糊塗的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kokoya");
        set("owner_name", "難得糊塗");
        set_temp("owner", "kokoya");
        set_temp("owner_name", "難得糊塗");
        ::setup();
}
