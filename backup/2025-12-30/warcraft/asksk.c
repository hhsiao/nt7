// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m小綠馬[2;37;0m[2;37;0m", ({"jinju"}));        
        set("gender", "男性");                
        set("long", "一披矯健的千里馬[2;37;0m
它是沒影子的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "asksk");
        set("owner_name", "沒影子");
        set_temp("owner", "asksk");
        set_temp("owner_name", "沒影子");
        ::setup();
}
