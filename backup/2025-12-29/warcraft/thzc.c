// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m驢[1;33m車[2;37;0m[2;37;0m", ({"lvche"}));        
        set("gender", "男性");                
        set("long", "這是長工們的坐騎[2;37;0m
它是長工丙的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "thzc");
        set("owner_name", "長工丙");
        set_temp("owner", "thzc");
        set_temp("owner_name", "長工丙");
        ::setup();
}
