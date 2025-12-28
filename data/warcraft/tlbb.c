// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("一葉扁舟[2;37;0m[2;37;0m", ({"tljbb"}));        
        set("gender", "男性");                
        set("long", "淡淡的山水之間[2;37;0m
它是天龍八部的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tlbb");
        set("owner_name", "天龍八部");
        set_temp("owner", "tlbb");
        set_temp("owner_name", "天龍八部");
        ::setup();
}
