// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小豬兒[2;37;0m[2;37;0m", ({"zzzq"}));        
        set("gender", "男性");                
        set("long", "小豬兒[2;37;0m
它是中校的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hslowek");
        set("owner_name", "中校");
        set_temp("owner", "hslowek");
        set_temp("owner_name", "中校");
        ::setup();
}
