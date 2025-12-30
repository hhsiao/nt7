// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m瘸腿老黃狗[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這頭黃狗又老又醜，渾身斑癬，芙蓉姐姐的性工具。[2;37;0m
它是菊花姐姐的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "juhua");
        set("owner_name", "菊花姐姐");
        set_temp("owner", "juhua");
        set_temp("owner_name", "菊花姐姐");
        ::setup();
}
