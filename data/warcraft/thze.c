// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m驢[1;33m車[2;37;0m[2;37;0m", ({"lvche"}));        
        set("gender", "男性");                
        set("long", "這是長工們的坐騎[2;37;0m
它是長工戊的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "thze");
        set("owner_name", "長工戊");
        set_temp("owner", "thze");
        set_temp("owner_name", "長工戊");
        ::setup();
}
