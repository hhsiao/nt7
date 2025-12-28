// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大貓[2;37;0m[2;37;0m", ({"bigcat"}));        
        set("gender", "男性");                
        set("long", "大貓[2;37;0m
它是幻雲的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hyun");
        set("owner_name", "幻雲");
        set_temp("owner", "hyun");
        set_temp("owner_name", "幻雲");
        ::setup();
}
