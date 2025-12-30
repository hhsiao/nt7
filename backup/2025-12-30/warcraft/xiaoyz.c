// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("東方不敗[2;37;0m[2;37;0m", ({"bubai"}));        
        set("gender", "女性");                
        set("long", "笑傲江湖[2;37;0m
它是令狐沖的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaoyz");
        set("owner_name", "令狐沖");
        set_temp("owner", "xiaoyz");
        set_temp("owner_name", "令狐沖");
        ::setup();
}
