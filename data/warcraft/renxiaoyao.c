// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("瑞獸自在麒麟[2;37;0m[2;37;0m", ({"xiaoyaoqilin"}));        
        set("gender", "男性");                
        set("long", "瑞獸自在麒麟[2;37;0m
它是張鬱悶的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "renxiaoyao");
        set("owner_name", "張鬱悶");
        set_temp("owner", "renxiaoyao");
        set_temp("owner_name", "張鬱悶");
        ::setup();
}
