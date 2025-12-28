// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"seiyl"}));        
        set("gender", "男性");                
        set("long", "火紅色，相當華麗的一隻大型鳥（？）類[2;37;0m
它是雨裳的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "seiy");
        set("owner_name", "雨裳");
        set_temp("owner", "seiy");
        set_temp("owner_name", "雨裳");
        ::setup();
}
