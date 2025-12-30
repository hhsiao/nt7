// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m青龍[2;37;0m[2;37;0m", ({"myshou"}));        
        set("gender", "女性");                
        set("long", "四大神獸之一的青龍[2;37;0m
它是明玉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hsdm");
        set("owner_name", "明玉");
        set_temp("owner", "hsdm");
        set_temp("owner_name", "明玉");
        ::setup();
}
