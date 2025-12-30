// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m保鏢[2;37;0m[2;37;0m", ({"bao"}));        
        set("gender", "女性");                
        set("long", "中南海保鏢[2;37;0m
它是中南海的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "gyill");
        set("owner_name", "中南海");
        set_temp("owner", "gyill");
        set_temp("owner_name", "中南海");
        ::setup();
}
