// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m輸出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是裝備讓人的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cairr");
        set("owner_name", "裝備讓人");
        set_temp("owner", "cairr");
        set_temp("owner_name", "裝備讓人");
        ::setup();
}
