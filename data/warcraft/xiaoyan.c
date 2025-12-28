// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("可愛[2;37;0m[2;37;0m", ({"keai"}));        
        set("gender", "女性");                
        set("long", "可愛動人的人[2;37;0m
它是小鹽的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaoyan");
        set("owner_name", "小鹽");
        set_temp("owner", "xiaoyan");
        set_temp("owner_name", "小鹽");
        ::setup();
}
