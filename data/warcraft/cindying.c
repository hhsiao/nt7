// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("炮彈[2;37;0m[2;37;0m", ({"ook"}));        
        set("gender", "男性");                
        set("long", "炮彈[2;37;0m
它是火龍的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "cindying");
        set("owner_name", "火龍");
        set_temp("owner", "cindying");
        set_temp("owner_name", "火龍");
        ::setup();
}
