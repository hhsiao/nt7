// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m玄[1;34m武[2;37;0m[2;37;0m", ({"tortoise"}));        
        set("gender", "男性");                
        set("long", "一隻大大大大大大大的烏龜。[2;37;0m
它是竹木一橫的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "smart");
        set("owner_name", "竹木一橫");
        set_temp("owner", "smart");
        set_temp("owner_name", "竹木一橫");
        ::setup();
}
