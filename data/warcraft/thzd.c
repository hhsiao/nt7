// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m驢[1;33m車[2;37;0m[2;37;0m", ({"lvche"}));        
        set("gender", "男性");                
        set("long", "這是長工們的坐騎[2;37;0m
它是長工丁的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "thzd");
        set("owner_name", "長工丁");
        set_temp("owner", "thzd");
        set_temp("owner_name", "長工丁");
        ::setup();
}
