// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小青龍[2;37;0m[2;37;0m", ({"qinglonga"}));        
        set("gender", "男性");                
        set("long", "我是一隻小青龍，小青龍，我有許多小秘密，小秘密。[2;37;0m
它是東方常勝的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "eastwinner");
        set("owner_name", "東方常勝");
        set_temp("owner", "eastwinner");
        set_temp("owner_name", "東方常勝");
        ::setup();
}
