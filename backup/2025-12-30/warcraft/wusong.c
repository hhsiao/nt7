// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m踏[1;37m雪[1;34m烏錐[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹馬全身烏黑亮麗，無一根雜色，宛如錦緞，龍吟虎相。[2;37;0m
它是武松的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wusong");
        set("owner_name", "武松");
        set_temp("owner", "wusong");
        set_temp("owner_name", "武松");
        ::setup();
}
