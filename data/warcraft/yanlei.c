// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m右白虎[2;37;0m[2;37;0m", ({"tiger"}));        
        set("gender", "男性");                
        set("long", "右白虎[2;37;0m
它是眼淚的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "yanlei");
        set("owner_name", "眼淚");
        set_temp("owner", "yanlei");
        set_temp("owner_name", "眼淚");
        ::setup();
}
