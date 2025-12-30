// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m瑞獸[2;37;0m[2;37;0m", ({"xfh"}));        
        set("gender", "男性");                
        set("long", "懶[2;37;0m
它是夢紅塵的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "plk");
        set("owner_name", "夢紅塵");
        set_temp("owner", "plk");
        set_temp("owner_name", "夢紅塵");
        ::setup();
}
