// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("我是一隻鳥[2;37;0m[2;37;0m", ({"bird"}));        
        set("gender", "男性");                
        set("long", "我是一隻鳥[2;37;0m
它是罐罐剛剛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ggg");
        set("owner_name", "罐罐剛剛");
        set_temp("owner", "ggg");
        set_temp("owner_name", "罐罐剛剛");
        ::setup();
}
