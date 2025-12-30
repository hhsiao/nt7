// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m小綠茶[2;37;0m[2;37;0m", ({"spceial"}));        
        set("gender", "女性");                
        set("long", "小綠茶[2;37;0m
它是豬大的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "special");
        set("owner_name", "豬大");
        set_temp("owner", "special");
        set_temp("owner_name", "豬大");
        ::setup();
}
