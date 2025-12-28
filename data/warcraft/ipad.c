// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m妖獸[2;37;0m[2;37;0m", ({"sss"}));        
        set("gender", "男性");                
        set("long", "妖惑眾生[2;37;0m
它是蘋果的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ipad");
        set("owner_name", "蘋果");
        set_temp("owner", "ipad");
        set_temp("owner_name", "蘋果");
        ::setup();
}
