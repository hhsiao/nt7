// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("桃花瑞獸麒麟[2;37;0m[2;37;0m", ({"huangyingqilin"}));        
        set("gender", "女性");                
        set("long", "桃花瑞獸麒麟[2;37;0m
它是黃英的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "taohuamz");
        set("owner_name", "黃英");
        set_temp("owner", "taohuamz");
        set_temp("owner_name", "黃英");
        ::setup();
}
