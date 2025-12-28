// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m千年殺[2;37;0m[2;37;0m", ({"wuchi"}));        
        set("gender", "男性");                
        set("long", "靈感塔上的武痴[2;37;0m
它是剎那芳華的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cnfh");
        set("owner_name", "剎那芳華");
        set_temp("owner", "cnfh");
        set_temp("owner_name", "剎那芳華");
        ::setup();
}
