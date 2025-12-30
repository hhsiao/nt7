// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m真愛三龍[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "女性");                
        set("long", "我愛我的龍龍[2;37;0m
它是李三爭的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lizhengc");
        set("owner_name", "李三爭");
        set_temp("owner", "lizhengc");
        set_temp("owner_name", "李三爭");
        ::setup();
}
