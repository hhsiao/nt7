// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m驢[1;33m車[2;37;0m[2;37;0m", ({"lvche"}));        
        set("gender", "男性");                
        set("long", "這是給長工們的坐騎[2;37;0m
它是長工甲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "thza");
        set("owner_name", "長工甲");
        set_temp("owner", "thza");
        set_temp("owner_name", "長工甲");
        ::setup();
}
