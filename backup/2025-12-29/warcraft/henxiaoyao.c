// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("瑞獸麒麟王[2;37;0m[2;37;0m", ({"xiaoqilin"}));        
        set("gender", "男性");                
        set("long", "瑞獸麒麟王[2;37;0m
它是張逍逍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "henxiaoyao");
        set("owner_name", "張逍逍");
        set_temp("owner", "henxiaoyao");
        set_temp("owner_name", "張逍逍");
        ::setup();
}
