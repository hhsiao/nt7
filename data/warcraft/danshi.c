// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小雪[2;37;0m[2;37;0m", ({"mud"}));        
        set("gender", "女性");                
        set("long", "多雲[2;37;0m
它是煉丹師的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "danshi");
        set("owner_name", "煉丹師");
        set_temp("owner", "danshi");
        set_temp("owner_name", "煉丹師");
        ::setup();
}
