// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m風[1;34m雷[5m[2;37;0m[2;37;0m", ({"zyy"}));        
        set("gender", "女性");                
        set("long", "一聲驚雷從天降，風火燒成萬骨灰[2;37;0m
它是殘天的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "zzy");
        set("owner_name", "殘天");
        set_temp("owner", "zzy");
        set_temp("owner_name", "殘天");
        ::setup();
}
