// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m麒麟獸[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "我的座駕[2;37;0m
它是馬嘯天的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mali");
        set("owner_name", "馬嘯天");
        set_temp("owner", "mali");
        set_temp("owner_name", "馬嘯天");
        ::setup();
}
