// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是歐陽峰的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ouyangfeng");
        set("owner_name", "歐陽峰");
        set_temp("owner", "ouyangfeng");
        set_temp("owner_name", "歐陽峰");
        ::setup();
}
