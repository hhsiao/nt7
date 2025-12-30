// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("隱形[2;37;0m[2;37;0m", ({"laihama"}));        
        set("gender", "男性");                
        set("long", "finish[2;37;0m
它是歐陽人傑的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kiyotu");
        set("owner_name", "歐陽人傑");
        set_temp("owner", "kiyotu");
        set_temp("owner_name", "歐陽人傑");
        ::setup();
}
