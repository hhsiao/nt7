// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("聆聽我的傾訴[2;37;0m[2;37;0m", ({"xiaoqueque"}));        
        set("gender", "女性");                
        set("long", "聆聽我的傾訴[2;37;0m
它是靜六的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jingf");
        set("owner_name", "靜六");
        set_temp("owner", "jingf");
        set_temp("owner_name", "靜六");
        ::setup();
}
