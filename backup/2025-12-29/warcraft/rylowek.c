// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍龍[2;37;0m[2;37;0m", ({"ryqinglong"}));        
        set("gender", "男性");                
        set("long", "小龍龍[2;37;0m
它是中蕭的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "rylowek");
        set("owner_name", "中蕭");
        set_temp("owner", "rylowek");
        set_temp("owner_name", "中蕭");
        ::setup();
}
