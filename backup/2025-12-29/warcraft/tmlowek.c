// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m蝕日鳳凰[1;36m[5m[2;37;0m[2;37;0m", ({"tmzq"}));        
        set("gender", "男性");                
        set("long", "開襠褲碟片[2;37;0m
它是小標的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tmlowek");
        set("owner_name", "小標");
        set_temp("owner", "tmlowek");
        set_temp("owner_name", "小標");
        ::setup();
}
