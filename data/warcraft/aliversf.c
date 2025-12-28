// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m猛禽戰機[2;37;0m[2;37;0m", ({"pesic"}));        
        set("gender", "男性");                
        set("long", "猛禽戰機[2;37;0m
它是阿爾六的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "aliversf");
        set("owner_name", "阿爾六");
        set_temp("owner", "aliversf");
        set_temp("owner_name", "阿爾六");
        ::setup();
}
