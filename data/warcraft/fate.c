// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[33m拉[33m土[33m車[2;37;0m[2;37;0m", ({"fatff"}));        
        set("gender", "女性");                
        set("long", "拉土車[2;37;0m
它是煉藥五的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fate");
        set("owner_name", "煉藥五");
        set_temp("owner", "fate");
        set_temp("owner_name", "煉藥五");
        ::setup();
}
