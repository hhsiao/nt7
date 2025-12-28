// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("嘻嘻[2;37;0m[2;37;0m", ({"xixixi"}));        
        set("gender", "男性");                
        set("long", "xxx[2;37;0m
它是哈哈爾的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hahaha");
        set("owner_name", "哈哈爾");
        set_temp("owner", "hahaha");
        set_temp("owner_name", "哈哈爾");
        ::setup();
}
