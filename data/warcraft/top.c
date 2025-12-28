// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哈哈[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是上單的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "top");
        set("owner_name", "上單");
        set_temp("owner", "top");
        set_temp("owner_name", "上單");
        ::setup();
}
