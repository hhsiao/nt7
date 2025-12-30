// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m黃沙[2;37;0m[2;37;0m", ({"qfx"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是一陣風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "windy");
        set("owner_name", "一陣風");
        set_temp("owner", "windy");
        set_temp("owner_name", "一陣風");
        ::setup();
}
