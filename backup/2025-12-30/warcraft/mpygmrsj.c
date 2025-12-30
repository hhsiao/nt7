// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;33m世京[2;37;0m[2;37;0m", ({"murongpai"}));        
        set("gender", "男性");                
        set("long", "$BLINK$$HIY$世京[2;37;0m
它是駐天的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mpygmrsj");
        set("owner_name", "駐天");
        set_temp("owner", "mpygmrsj");
        set_temp("owner_name", "駐天");
        ::setup();
}
