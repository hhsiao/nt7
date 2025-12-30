// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m珈迪魔龍[2;37;0m[2;37;0m", ({"molong"}));        
        set("gender", "女性");                
        set("long", "珈迪魔龍[2;37;0m
它是小敏的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "minmin");
        set("owner_name", "小敏");
        set_temp("owner", "minmin");
        set_temp("owner_name", "小敏");
        ::setup();
}
