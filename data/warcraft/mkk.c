// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"fkaa"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是曼蠻的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mkk");
        set("owner_name", "曼蠻");
        set_temp("owner", "mkk");
        set_temp("owner_name", "曼蠻");
        ::setup();
}
