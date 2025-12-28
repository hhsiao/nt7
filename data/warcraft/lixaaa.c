// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小紅[2;37;0m[2;37;0m", ({"xiaohong"}));        
        set("gender", "女性");                
        set("long", "誠實可愛的小母麒麟[2;37;0m
它是雨雪飛的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lixaaa");
        set("owner_name", "雨雪飛");
        set_temp("owner", "lixaaa");
        set_temp("owner_name", "雨雪飛");
        ::setup();
}
