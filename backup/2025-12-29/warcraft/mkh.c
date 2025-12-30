// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"fkaa"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是曼紅的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mkh");
        set("owner_name", "曼紅");
        set_temp("owner", "mkh");
        set_temp("owner_name", "曼紅");
        ::setup();
}
