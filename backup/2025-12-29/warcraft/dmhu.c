// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("紫雲獸[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "紫雲獸[2;37;0m
它是胡來的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dmhu");
        set("owner_name", "胡來");
        set_temp("owner", "dmhu");
        set_temp("owner_name", "胡來");
        ::setup();
}
