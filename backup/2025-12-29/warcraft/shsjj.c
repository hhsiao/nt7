// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小小鳥[2;37;0m[2;37;0m", ({"bird"}));        
        set("gender", "男性");                
        set("long", "小小鳥[2;37;0m
它是迪卡儂的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "shsjj");
        set("owner_name", "迪卡儂");
        set_temp("owner", "shsjj");
        set_temp("owner_name", "迪卡儂");
        ::setup();
}
