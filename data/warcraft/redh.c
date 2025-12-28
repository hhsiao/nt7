// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "睡袋[2;37;0m
它是花蓮老祖的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "redh");
        set("owner_name", "花蓮老祖");
        set_temp("owner", "redh");
        set_temp("owner_name", "花蓮老祖");
        ::setup();
}
