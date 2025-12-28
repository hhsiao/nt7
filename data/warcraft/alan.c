// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小貓[2;37;0m[2;37;0m", ({"mao"}));        
        set("gender", "女性");                
        set("long", "一隻溫順的小貓[2;37;0m
它是書蘭的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "alan");
        set("owner_name", "書蘭");
        set_temp("owner", "alan");
        set_temp("owner_name", "書蘭");
        ::setup();
}
