// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("波比[2;37;0m[2;37;0m", ({"bobi"}));        
        set("gender", "男性");                
        set("long", "這奇異的怪獸，背上有著銀色毛髮，而頭上的獨角看上去顯得神俊。[2;37;0m
它是飛劍便便的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "perform");
        set("owner_name", "飛劍便便");
        set_temp("owner", "perform");
        set_temp("owner_name", "飛劍便便");
        ::setup();
}
