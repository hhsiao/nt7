// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("遠古青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "遠古青龍[2;37;0m
它是一偷的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mooktb");
        set("owner_name", "一偷");
        set_temp("owner", "mooktb");
        set_temp("owner_name", "一偷");
        ::setup();
}
