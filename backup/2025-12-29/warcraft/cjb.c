// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大西瓜[2;37;0m[2;37;0m", ({"wps"}));        
        set("gender", "男性");                
        set("long", "大西瓜[2;37;0m
它是夜聽風的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "cjb");
        set("owner_name", "夜聽風");
        set_temp("owner", "cjb");
        set_temp("owner_name", "夜聽風");
        ::setup();
}
