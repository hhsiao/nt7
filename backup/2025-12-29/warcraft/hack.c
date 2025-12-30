// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大貓[2;37;0m[2;37;0m", ({"lisam"}));        
        set("gender", "男性");                
        set("long", "大貓[2;37;0m
它是騎妹泡豬的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hack");
        set("owner_name", "騎妹泡豬");
        set_temp("owner", "hack");
        set_temp("owner_name", "騎妹泡豬");
        ::setup();
}
