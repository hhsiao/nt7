// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("紫雲獸[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "紫雲獸[2;37;0m
它是小壞蛋的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dmduan");
        set("owner_name", "小壞蛋");
        set_temp("owner", "dmduan");
        set_temp("owner_name", "小壞蛋");
        ::setup();
}
