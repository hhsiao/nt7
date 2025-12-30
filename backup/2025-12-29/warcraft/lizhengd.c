// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m真愛四龍[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "女性");                
        set("long", "我愛我的龍龍[2;37;0m
它是李四爭的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lizhengd");
        set("owner_name", "李四爭");
        set_temp("owner", "lizhengd");
        set_temp("owner_name", "李四爭");
        ::setup();
}
