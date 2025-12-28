// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("踏[1;37m雪[1;34m烏錐[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹馬全身烏黑亮麗，宛如錦緞，無一根雜色，龍吟虎步。[2;37;0m
它是呂秀才的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiucai");
        set("owner_name", "呂秀才");
        set_temp("owner", "xiucai");
        set_temp("owner_name", "呂秀才");
        ::setup();
}
