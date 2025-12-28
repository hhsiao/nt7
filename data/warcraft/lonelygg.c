// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小馬哥[2;37;0m[2;37;0m", ({"lonelyma"}));        
        set("gender", "男性");                
        set("long", "小馬哥[2;37;0m
它是功夫王的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lonelygg");
        set("owner_name", "功夫王");
        set_temp("owner", "lonelygg");
        set_temp("owner_name", "功夫王");
        ::setup();
}
