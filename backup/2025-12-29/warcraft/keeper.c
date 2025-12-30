// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m幽冥麒麟[2;37;0m[2;37;0m", ({"youming_qilin"}));        
        set("gender", "男性");                
        set("long", "幽冥麒麟[2;37;0m
它是廟祝的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "keeper");
        set("owner_name", "廟祝");
        set_temp("owner", "keeper");
        set_temp("owner_name", "廟祝");
        ::setup();
}
