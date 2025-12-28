// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m靚[1;31m爆[1;35m你[1;36m雙眼[2;37;0m[2;37;0m[2;37;0m", ({"blast"}));        
        set("gender", "女性");                
        set("long", "靚爆你雙眼![2;37;0m
它是妹紙賊拽的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "glamorous");
        set("owner_name", "妹紙賊拽");
        set_temp("owner", "glamorous");
        set_temp("owner_name", "妹紙賊拽");
        ::setup();
}
