// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("赤鏈蛇[2;37;0m[2;37;0m", ({"pla"}));        
        set("gender", "女性");                
        set("long", "不解釋。[2;37;0m
它是挖寶一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wbga");
        set("owner_name", "挖寶一");
        set_temp("owner", "wbga");
        set_temp("owner_name", "挖寶一");
        ::setup();
}
