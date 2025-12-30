// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大黃狗[2;37;0m[2;37;0m", ({"tcaibride"}));        
        set("gender", "男性");                
        set("long", "大黃狗[2;37;0m
它是納尼金的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tcaib");
        set("owner_name", "納尼金");
        set_temp("owner", "tcaib");
        set_temp("owner_name", "納尼金");
        ::setup();
}
