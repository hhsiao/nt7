// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雪鳥[2;37;0m[2;37;0m", ({"xueoo"}));        
        set("gender", "女性");                
        set("long", "雪鳥[2;37;0m
它是藍雪子的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wxue");
        set("owner_name", "藍雪子");
        set_temp("owner", "wxue");
        set_temp("owner_name", "藍雪子");
        ::setup();
}
