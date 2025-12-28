// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m踏雪[1;34m烏錐[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹馬全身烏黑亮麗、宛如錦緞，唯有四蹄白色，龍吟虎步。[2;37;0m
它是李逵的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lkui");
        set("owner_name", "李逵");
        set_temp("owner", "lkui");
        set_temp("owner_name", "李逵");
        ::setup();
}
