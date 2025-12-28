// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("瑞獸玉麒麟[2;37;0m[2;37;0m", ({"owenqilin"}));        
        set("gender", "男性");                
        set("long", "瑞獸玉麒麟[2;37;0m
它是張大千的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dearowen");
        set("owner_name", "張大千");
        set_temp("owner", "dearowen");
        set_temp("owner_name", "張大千");
        ::setup();
}
