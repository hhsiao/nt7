// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m輸出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是靈感脫離的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lgu");
        set("owner_name", "靈感脫離");
        set_temp("owner", "lgu");
        set_temp("owner_name", "靈感脫離");
        ::setup();
}
