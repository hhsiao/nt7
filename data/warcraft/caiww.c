// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m輸出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是幾個用了的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "caiww");
        set("owner_name", "幾個用了");
        set_temp("owner", "caiww");
        set_temp("owner_name", "幾個用了");
        ::setup();
}
