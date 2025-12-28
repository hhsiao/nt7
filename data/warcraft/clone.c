// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m冰[1;35m激[1;36m凌[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "很萌很搶手[2;37;0m
它是蒼龍甲的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "clone");
        set("owner_name", "蒼龍甲");
        set_temp("owner", "clone");
        set_temp("owner_name", "蒼龍甲");
        ::setup();
}
