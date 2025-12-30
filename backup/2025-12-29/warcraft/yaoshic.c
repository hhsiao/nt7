// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("坐騎[2;37;0m[2;37;0m", ({"zuoqic"}));        
        set("gender", "男性");                
        set("long", "坐騎[2;37;0m
它是藥師三的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yaoshic");
        set("owner_name", "藥師三");
        set_temp("owner", "yaoshic");
        set_temp("owner_name", "藥師三");
        ::setup();
}
