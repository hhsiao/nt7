// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("赤木晴子[2;37;0m[2;37;0m", ({"plb"}));        
        set("gender", "女性");                
        set("long", "不解釋[2;37;0m
它是挖寶二的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wbgb");
        set("owner_name", "挖寶二");
        set_temp("owner", "wbgb");
        set_temp("owner_name", "挖寶二");
        ::setup();
}
