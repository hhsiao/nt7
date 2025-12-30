// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m小鳥[2;37;0m[2;37;0m", ({"xiaobai"}));        
        set("gender", "男性");                
        set("long", "一隻小小鳥[2;37;0m
它是風飛二揚的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "seeflyb");
        set("owner_name", "風飛二揚");
        set_temp("owner", "seeflyb");
        set_temp("owner_name", "風飛二揚");
        ::setup();
}
