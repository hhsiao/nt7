// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m魅影[2;37;0m[2;37;0m", ({"meiying"}));        
        set("gender", "男性");                
        set("long", "$BLINK$$HIG$魅影[2;37;0m
它是西方失敗的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "westfail");
        set("owner_name", "西方失敗");
        set_temp("owner", "westfail");
        set_temp("owner_name", "西方失敗");
        ::setup();
}
