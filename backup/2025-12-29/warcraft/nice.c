// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m日本鬼子[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "一個日本鬼子[2;37;0m
它是腦障礙者的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nice");
        set("owner_name", "腦障礙者");
        set_temp("owner", "nice");
        set_temp("owner_name", "腦障礙者");
        ::setup();
}
