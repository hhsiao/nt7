// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m窮窮窮[2;37;0m[2;37;0m[2;37;0m", ({"nomoney"}));        
        set("gender", "男性");                
        set("long", "一隻神秘的怪獸[2;37;0m
它是猴王的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "monkey");
        set("owner_name", "猴王");
        set_temp("owner", "monkey");
        set_temp("owner_name", "猴王");
        ::setup();
}
