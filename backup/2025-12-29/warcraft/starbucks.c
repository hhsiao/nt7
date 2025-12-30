// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("買一送一[2;37;0m[2;37;0m", ({"allone"}));        
        set("gender", "男性");                
        set("long", "來星巴克有不定期買一送一唷^^[2;37;0m
它是星巴克的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "starbucks");
        set("owner_name", "星巴克");
        set_temp("owner", "starbucks");
        set_temp("owner_name", "星巴克");
        ::setup();
}
