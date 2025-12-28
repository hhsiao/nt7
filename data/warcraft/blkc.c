// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m劉德華[2;37;0m[2;37;0m", ({"liudehua"}));        
        set("gender", "男性");                
        set("long", "香港演員[2;37;0m
它是罪無可恕的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "blkc");
        set("owner_name", "罪無可恕");
        set_temp("owner", "blkc");
        set_temp("owner_name", "罪無可恕");
        ::setup();
}
