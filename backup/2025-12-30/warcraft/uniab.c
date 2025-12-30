// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小鳥[2;37;0m[2;37;0m", ({"tutu"}));        
        set("gender", "女性");                
        set("long", "這是一隻可愛的小鳥[2;37;0m
它是葉一二的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "uniab");
        set("owner_name", "葉一二");
        set_temp("owner", "uniab");
        set_temp("owner_name", "葉一二");
        ::setup();
}
