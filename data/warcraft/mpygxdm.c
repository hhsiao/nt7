// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m血色之刃[2;37;0m[2;37;0m", ({"xuedaomen"}));        
        set("gender", "男性");                
        set("long", "$BLINK$$HIR$血色之刃[2;37;0m
它是萬佛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mpygxdm");
        set("owner_name", "萬佛");
        set_temp("owner", "mpygxdm");
        set_temp("owner_name", "萬佛");
        ::setup();
}
