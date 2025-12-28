// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("坑貨[2;37;0m[2;37;0m", ({"xing"}));        
        set("gender", "男性");                
        set("long", "xiaoxiao的坐騎[2;37;0m
它是曉曉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaoxiao");
        set("owner_name", "曉曉");
        set_temp("owner", "xiaoxiao");
        set_temp("owner_name", "曉曉");
        ::setup();
}
