// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m紅蓮老豬[2;37;0m[2;37;0m", ({"redi"}));        
        set("gender", "男性");                
        set("long", "。。。。[2;37;0m
它是綠蓮老豬的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "rcdl");
        set("owner_name", "綠蓮老豬");
        set_temp("owner", "rcdl");
        set_temp("owner_name", "綠蓮老豬");
        ::setup();
}
