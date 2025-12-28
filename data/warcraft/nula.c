// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "請你以最深的靈性，聆聽我的傾訴[2;37;0m
它是桃花魚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "nula");
        set("owner_name", "桃花魚");
        set_temp("owner", "nula");
        set_temp("owner_name", "桃花魚");
        ::setup();
}
