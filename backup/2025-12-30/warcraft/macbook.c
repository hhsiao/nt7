// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m蘋果手機[2;37;0m[2;37;0m", ({"iphone"}));        
        set("gender", "男性");                
        set("long", "$HIR$蘋果手機[2;37;0m
它是蘋果電腦的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "macbook");
        set("owner_name", "蘋果電腦");
        set_temp("owner", "macbook");
        set_temp("owner_name", "蘋果電腦");
        ::setup();
}
