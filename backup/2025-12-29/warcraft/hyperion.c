// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[35m露[5m[35m露[2;37;0m[2;37;0m", ({"lulu"}));        
        set("gender", "女性");                
        set("long", "只[2;37;0m
它是唐老鴨的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hyperion");
        set("owner_name", "唐老鴨");
        set_temp("owner", "hyperion");
        set_temp("owner_name", "唐老鴨");
        ::setup();
}
