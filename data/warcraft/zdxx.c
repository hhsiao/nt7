// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豐[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "豐[2;37;0m
它是東非的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zdxx");
        set("owner_name", "東非");
        set_temp("owner", "zdxx");
        set_temp("owner_name", "東非");
        ::setup();
}
