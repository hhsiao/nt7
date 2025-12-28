// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m輸出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是菜寶寶的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "caibb");
        set("owner_name", "菜寶寶");
        set_temp("owner", "caibb");
        set_temp("owner_name", "菜寶寶");
        ::setup();
}
