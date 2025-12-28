// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小李子[2;37;0m[2;37;0m", ({"lijie"}));        
        set("gender", "女性");                
        set("long", "忠實的夥伴[2;37;0m
它是蒼蒼的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "piap");
        set("owner_name", "蒼蒼");
        set_temp("owner", "piap");
        set_temp("owner_name", "蒼蒼");
        ::setup();
}
