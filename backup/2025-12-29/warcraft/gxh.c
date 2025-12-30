// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("竹笛[2;37;0m[2;37;0m", ({"ggg"}));        
        set("gender", "男性");                
        set("long", "懶[2;37;0m
它是夢醉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "gxh");
        set("owner_name", "夢醉");
        set_temp("owner", "gxh");
        set_temp("owner_name", "夢醉");
        ::setup();
}
