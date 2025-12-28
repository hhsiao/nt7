// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m夢[2;37;0m[2;37;0m", ({"meng"}));        
        set("gender", "女性");                
        set("long", "這是夢，一隻強大的幻獸。[2;37;0m
它是唐瀾的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tlan");
        set("owner_name", "唐瀾");
        set_temp("owner", "tlan");
        set_temp("owner_name", "唐瀾");
        ::setup();
}
