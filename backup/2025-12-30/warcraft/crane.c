// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雲兒[2;37;0m[2;37;0m", ({"ccloud"}));        
        set("gender", "男性");                
        set("long", "雲兒[2;37;0m
它是雲沙的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "crane");
        set("owner_name", "雲沙");
        set_temp("owner", "crane");
        set_temp("owner_name", "雲沙");
        ::setup();
}
