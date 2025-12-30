// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m狂蟒[2;37;0m[2;37;0m", ({"boa"}));        
        set("gender", "男性");                
        set("long", "一條瘋狂的巨蛇，它正在狠狠地盯著你，彷彿可以看穿你的一切。[2;37;0m
它是小貓弟的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaomaodi");
        set("owner_name", "小貓弟");
        set_temp("owner", "xiaomaodi");
        set_temp("owner_name", "小貓弟");
        ::setup();
}
