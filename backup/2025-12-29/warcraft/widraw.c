// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("一隻朱雀[2;37;0m[2;37;0m", ({"filter"}));        
        set("gender", "男性");                
        set("long", "一隻朱雀[2;37;0m
它是陳宏的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "widraw");
        set("owner_name", "陳宏");
        set_temp("owner", "widraw");
        set_temp("owner_name", "陳宏");
        ::setup();
}
