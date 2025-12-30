// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("遠古青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "遠古青龍[2;37;0m
它是清丹的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mookta");
        set("owner_name", "清丹");
        set_temp("owner", "mookta");
        set_temp("owner_name", "清丹");
        ::setup();
}
