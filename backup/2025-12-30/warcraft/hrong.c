// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m踏雪[1;34m烏錐[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹馬全身如黑緞一般，四蹄白色，追風逐電、神駿非凡。[2;37;0m
它是花榮的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hrong");
        set("owner_name", "花榮");
        set_temp("owner", "hrong");
        set_temp("owner_name", "花榮");
        ::setup();
}
