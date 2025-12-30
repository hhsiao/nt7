// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小耗子[2;37;0m[2;37;0m", ({"mouse"}));        
        set("gender", "女性");                
        set("long", "小耗子[2;37;0m
它是糖醋鯉魚的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cindyll");
        set("owner_name", "糖醋鯉魚");
        set_temp("owner", "cindyll");
        set_temp("owner_name", "糖醋鯉魚");
        ::setup();
}
