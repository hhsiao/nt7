// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m小鳳雞[2;37;0m[2;37;0m", ({"xfj"}));        
        set("gender", "女性");                
        set("long", "一隻沒成長的朱雀。[2;37;0m
它是大忙人的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dmr");
        set("owner_name", "大忙人");
        set_temp("owner", "dmr");
        set_temp("owner_name", "大忙人");
        ::setup();
}
