// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("瀧澤蘿拉[1;37m[2;37;0m[2;37;0m", ({"feiji"}));        
        set("gender", "男性");                
        set("long", "瀧澤蘿拉[2;37;0m
它是蕭十一郎的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "superjl");
        set("owner_name", "蕭十一郎");
        set_temp("owner", "superjl");
        set_temp("owner_name", "蕭十一郎");
        ::setup();
}
