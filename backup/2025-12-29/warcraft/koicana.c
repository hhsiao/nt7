// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("回答速度[2;37;0m[2;37;0m", ({"yiyayo"}));        
        set("gender", "女性");                
        set("long", "的發放[2;37;0m
它是終極倉庫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "koicana");
        set("owner_name", "終極倉庫");
        set_temp("owner", "koicana");
        set_temp("owner_name", "終極倉庫");
        ::setup();
}
