// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("附屬[2;37;0m[2;37;0m", ({"cncpp"}));        
        set("gender", "男性");                
        set("long", "附屬[2;37;0m
它是飛鷹十三的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cnflyfire");
        set("owner_name", "飛鷹十三");
        set_temp("owner", "cnflyfire");
        set_temp("owner_name", "飛鷹十三");
        ::setup();
}
