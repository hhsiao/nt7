// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小貓[2;37;0m[2;37;0m", ({"xmao"}));        
        set("gender", "男性");                
        set("long", "小貓[2;37;0m
它是藥童的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "yyao");
        set("owner_name", "藥童");
        set_temp("owner", "yyao");
        set_temp("owner_name", "藥童");
        ::setup();
}
