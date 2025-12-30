// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("壞掉了[2;37;0m[2;37;0m", ({"waw"}));        
        set("gender", "男性");                
        set("long", "就壞掉了[2;37;0m
它是高潮腎寒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "waa");
        set("owner_name", "高潮腎寒");
        set_temp("owner", "waa");
        set_temp("owner_name", "高潮腎寒");
        ::setup();
}
