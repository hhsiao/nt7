// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白雲[2;37;0m[2;37;0m", ({"baiyun"}));        
        set("gender", "女性");                
        set("long", "飄浮天空的浮雲[2;37;0m
它是小蘭的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaolan");
        set("owner_name", "小蘭");
        set_temp("owner", "xiaolan");
        set_temp("owner_name", "小蘭");
        ::setup();
}
