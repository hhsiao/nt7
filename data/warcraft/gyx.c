// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m玉蛟龍[2;37;0m[2;37;0m", ({"gyxds"}));        
        set("gender", "男性");                
        set("long", "浮雲神馬，所向無敵[2;37;0m
它是顧玉俠的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gyx");
        set("owner_name", "顧玉俠");
        set_temp("owner", "gyx");
        set_temp("owner_name", "顧玉俠");
        ::setup();
}
