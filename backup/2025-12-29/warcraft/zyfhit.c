// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[36m閒雲野鶴[2;37;0m[2;37;0m", ({"zyfma"}));        
        set("gender", "男性");                
        set("long", "塵非塵的坐騎[2;37;0m
它是塵非塵的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zyfhit");
        set("owner_name", "塵非塵");
        set_temp("owner", "zyfhit");
        set_temp("owner_name", "塵非塵");
        ::setup();
}
