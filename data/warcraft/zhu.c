// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白龍馬[2;37;0m[2;37;0m", ({"fff"}));        
        set("gender", "女性");                
        set("long", "白龍馬[2;37;0m
它是蛛兒的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zhu");
        set("owner_name", "蛛兒");
        set_temp("owner", "zhu");
        set_temp("owner_name", "蛛兒");
        ::setup();
}
