// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("響尾蛇[2;37;0m[2;37;0m", ({"danshui"}));        
        set("gender", "男性");                
        set("long", "響尾蛇[2;37;0m
它是黃花菜的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dandan");
        set("owner_name", "黃花菜");
        set_temp("owner", "dandan");
        set_temp("owner_name", "黃花菜");
        ::setup();
}
