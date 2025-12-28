// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m魁花寶典[2;37;0m[2;37;0m", ({"kuihuabaodian"}));        
        set("gender", "女性");                
        set("long", "$BLINK$$HIG$魁花寶典[2;37;0m
它是西方失敗的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xifang");
        set("owner_name", "西方失敗");
        set_temp("owner", "xifang");
        set_temp("owner_name", "西方失敗");
        ::setup();
}
