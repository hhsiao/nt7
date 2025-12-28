// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m瘸腿老叫驢[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這頭老叫驢又老又醜，渾身斑癬，芙蓉姐姐的性工具[2;37;0m
它是金三胖的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sanpang");
        set("owner_name", "金三胖");
        set_temp("owner", "sanpang");
        set_temp("owner_name", "金三胖");
        ::setup();
}
