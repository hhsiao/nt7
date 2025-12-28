// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("碧水晶晶獸[2;37;0m[2;37;0m", ({"super"}));        
        set("gender", "男性");                
        set("long", "兩隻耳朵豎起來[2;37;0m
它是莫須有的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "upp");
        set("owner_name", "莫須有");
        set_temp("owner", "upp");
        set_temp("owner_name", "莫須有");
        ::setup();
}
