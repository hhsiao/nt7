// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大歐文[2;37;0m[2;37;0m", ({"loih"}));        
        set("gender", "男性");                
        set("long", "大歐文[2;37;0m
它是花豬的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "huazhu");
        set("owner_name", "花豬");
        set_temp("owner", "huazhu");
        set_temp("owner_name", "花豬");
        ::setup();
}
