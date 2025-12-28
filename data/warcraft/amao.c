// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小貓[2;37;0m[2;37;0m", ({"xiaomao"}));        
        set("gender", "男性");                
        set("long", "這是一隻小貓。[2;37;0m
它是阿貓的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "amao");
        set("owner_name", "阿貓");
        set_temp("owner", "amao");
        set_temp("owner_name", "阿貓");
        ::setup();
}
