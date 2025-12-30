// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("酒井法子[2;37;0m[2;37;0m", ({"plc"}));        
        set("gender", "女性");                
        set("long", "不解釋。[2;37;0m
它是挖寶三的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wbgc");
        set("owner_name", "挖寶三");
        set_temp("owner", "wbgc");
        set_temp("owner_name", "挖寶三");
        ::setup();
}
