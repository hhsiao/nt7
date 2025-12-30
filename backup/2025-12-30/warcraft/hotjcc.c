// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m凱迪拉克[2;37;0m[2;37;0m", ({"hot"}));        
        set("gender", "男性");                
        set("long", "這是一輛世界頂級跑車。[2;37;0m
它是寒日的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hotjcc");
        set("owner_name", "寒日");
        set_temp("owner", "hotjcc");
        set_temp("owner_name", "寒日");
        ::setup();
}
