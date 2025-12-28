// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m千里馬[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "一匹千里馬[2;37;0m
它是沒影兒的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "mangmang");
        set("owner_name", "沒影兒");
        set_temp("owner", "mangmang");
        set_temp("owner_name", "沒影兒");
        ::setup();
}
