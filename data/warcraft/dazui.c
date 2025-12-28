// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m踏雪烏錐[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹馬全身烏黑亮麗，無一根雜色，宛如錦緞，龍聲虎步。[2;37;0m
它是李大嘴的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dazui");
        set("owner_name", "李大嘴");
        set_temp("owner", "dazui");
        set_temp("owner_name", "李大嘴");
        ::setup();
}
