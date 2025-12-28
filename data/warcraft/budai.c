// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("一隻麻布[2;37;0m[2;37;0m", ({"budaizi"}));        
        set("gender", "男性");                
        set("long", "一隻麻布[2;37;0m
它是麻布袋的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "budai");
        set("owner_name", "麻布袋");
        set_temp("owner", "budai");
        set_temp("owner_name", "麻布袋");
        ::setup();
}
