// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m冰[5m[1;37m雪[1;33m飄[1;32m零[2;37;0m[2;37;0m[2;37;0m", ({"snow"}));        
        set("gender", "女性");                
        set("long", "冰雪飄零ing...[2;37;0m
它是暴風雪的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "snowing");
        set("owner_name", "暴風雪");
        set_temp("owner", "snowing");
        set_temp("owner_name", "暴風雪");
        ::setup();
}
