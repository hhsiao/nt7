// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "睡袋[2;37;0m
它是黃二的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wyrsxqa");
        set("owner_name", "黃二");
        set_temp("owner", "wyrsxqa");
        set_temp("owner_name", "黃二");
        ::setup();
}
