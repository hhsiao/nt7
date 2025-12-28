// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "一隻[2;37;0m
它是飛揚在天的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaoai");
        set("owner_name", "飛揚在天");
        set_temp("owner", "xiaoai");
        set_temp("owner_name", "飛揚在天");
        ::setup();
}
