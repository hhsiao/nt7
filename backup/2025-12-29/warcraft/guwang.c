// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m蚩尤[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "這就是上古戰神蚩尤[2;37;0m
它是蠱王的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "guwang");
        set("owner_name", "蠱王");
        set_temp("owner", "guwang");
        set_temp("owner_name", "蠱王");
        ::setup();
}
