// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m驢[1;33m車[2;37;0m[2;37;0m", ({"lvche"}));        
        set("gender", "男性");                
        set("long", "這是長工們的坐騎[2;37;0m
它是長工乙的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "thzb");
        set("owner_name", "長工乙");
        set_temp("owner", "thzb");
        set_temp("owner_name", "長工乙");
        ::setup();
}
