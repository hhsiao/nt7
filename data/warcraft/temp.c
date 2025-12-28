// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("懵懂[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "懵懂[2;37;0m
它是騰蒲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "temp");
        set("owner_name", "騰蒲");
        set_temp("owner", "temp");
        set_temp("owner_name", "騰蒲");
        ::setup();
}
