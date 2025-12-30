// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m[1;31m飛火紅塵[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "飛火紅塵[2;37;0m
它是大聖的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "look");
        set("owner_name", "大聖");
        set_temp("owner", "look");
        set_temp("owner_name", "大聖");
        ::setup();
}
