// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m夢[2;37;0m[2;37;0m", ({"meng"}));        
        set("gender", "女性");                
        set("long", "這是就是夢。[2;37;0m
它是唐雪的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tanglan");
        set("owner_name", "唐雪");
        set_temp("owner", "tanglan");
        set_temp("owner_name", "唐雪");
        ::setup();
}
