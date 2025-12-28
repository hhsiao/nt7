// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白帝[1;37m[2;37;0m[2;37;0m", ({"xin"}));        
        set("gender", "男性");                
        set("long", "殺氣縱橫[2;37;0m
它是穀神不死的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "weag");
        set("owner_name", "穀神不死");
        set_temp("owner", "weag");
        set_temp("owner_name", "穀神不死");
        ::setup();
}
