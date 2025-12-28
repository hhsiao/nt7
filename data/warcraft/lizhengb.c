// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m真愛二龍[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "女性");                
        set("long", "我愛我的龍龍[2;37;0m
它是李二爭的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lizhengb");
        set("owner_name", "李二爭");
        set_temp("owner", "lizhengb");
        set_temp("owner_name", "李二爭");
        ::setup();
}
