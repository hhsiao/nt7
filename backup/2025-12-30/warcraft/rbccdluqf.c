// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是臺暉麗的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "rbccdluqf");
        set("owner_name", "臺暉麗");
        set_temp("owner", "rbccdluqf");
        set_temp("owner_name", "臺暉麗");
        ::setup();
}
