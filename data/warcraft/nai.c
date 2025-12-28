// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m皮娃娃[5m[1;37m劉強東[2;37;0m[2;37;0m", ({"car"}));        
        set("gender", "男性");                
        set("long", "這是京東銷量排名第一的劉強東版皮娃娃，眾多少女閨房必備。[2;37;0m
它是章澤天的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "nai");
        set("owner_name", "章澤天");
        set_temp("owner", "nai");
        set_temp("owner_name", "章澤天");
        ::setup();
}
