// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("包包[2;37;0m[2;37;0m", ({"bag"}));        
        set("gender", "女性");                
        set("long", "好貴[2;37;0m
它是騙人捱打的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "prada");
        set("owner_name", "騙人捱打");
        set_temp("owner", "prada");
        set_temp("owner_name", "騙人捱打");
        ::setup();
}
