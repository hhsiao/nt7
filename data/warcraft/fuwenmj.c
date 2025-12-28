// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("四不像[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "四不像[2;37;0m
它是唐小穎的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fuwenmj");
        set("owner_name", "唐小穎");
        set_temp("owner", "fuwenmj");
        set_temp("owner_name", "唐小穎");
        ::setup();
}
