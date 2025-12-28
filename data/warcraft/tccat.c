// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m菜問[2;37;0m[2;37;0m", ({"jinhu"}));        
        set("gender", "男性");                
        set("long", "菜問[2;37;0m
它是禱菜的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tccat");
        set("owner_name", "禱菜");
        set_temp("owner", "tccat");
        set_temp("owner_name", "禱菜");
        ::setup();
}
