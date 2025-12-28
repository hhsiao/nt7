// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("在天的見證之[2;37;0m[2;37;0m", ({"tiandejianzhengxia"}));        
        set("gender", "女性");                
        set("long", "在天的見證之[2;37;0m
它是靜七的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jingg");
        set("owner_name", "靜七");
        set_temp("owner", "jingg");
        set_temp("owner_name", "靜七");
        ::setup();
}
