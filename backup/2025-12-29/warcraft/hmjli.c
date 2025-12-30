// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("虎豹[2;37;0m[2;37;0m", ({"huhu"}));        
        set("gender", "男性");                
        set("long", "兇猛[2;37;0m
它是胡瘋神的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hmjli");
        set("owner_name", "胡瘋神");
        set_temp("owner", "hmjli");
        set_temp("owner_name", "胡瘋神");
        ::setup();
}
