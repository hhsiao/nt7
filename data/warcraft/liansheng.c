// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("花爵[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "花爵[2;37;0m
它是百鍊生的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "liansheng");
        set("owner_name", "百鍊生");
        set_temp("owner", "liansheng");
        set_temp("owner_name", "百鍊生");
        ::setup();
}
