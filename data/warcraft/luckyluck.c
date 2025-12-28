// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m招[5m[1;33m財[2;37;0m[1;35m進[5m[1;33m寶[2;37;0m[2;37;0m[2;37;0m", ({"treasure"}));        
        set("gender", "女性");                
        set("long", "招財進寶![2;37;0m
它是招財喵的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "luckyluck");
        set("owner_name", "招財喵");
        set_temp("owner", "luckyluck");
        set_temp("owner_name", "招財喵");
        ::setup();
}
