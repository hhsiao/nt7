// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鳳凰[2;37;0m[2;37;0m", ({"phoenix"}));        
        set("gender", "男性");                
        set("long", "鳳凰[2;37;0m
它是瀟瀟子的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "glfly");
        set("owner_name", "瀟瀟子");
        set_temp("owner", "glfly");
        set_temp("owner_name", "瀟瀟子");
        ::setup();
}
