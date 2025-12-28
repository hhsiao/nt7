// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("移動錢莊[2;37;0m[2;37;0m", ({"myma"}));        
        set("gender", "男性");                
        set("long", "一隻麒麟[2;37;0m
它是太多錢的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "duoduo");
        set("owner_name", "太多錢");
        set_temp("owner", "duoduo");
        set_temp("owner_name", "太多錢");
        ::setup();
}
