// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m[5m跟斗雲[2;37;0m[2;37;0m", ({"yun"}));        
        set("gender", "男性");                
        set("long", "龜仙人給的[2;37;0m
它是孫悟飯的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "wufan");
        set("owner_name", "孫悟飯");
        set_temp("owner", "wufan");
        set_temp("owner_name", "孫悟飯");
        ::setup();
}
