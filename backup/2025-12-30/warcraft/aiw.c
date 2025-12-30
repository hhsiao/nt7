// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小青青[2;37;0m[2;37;0m", ({"xiaobai"}));        
        set("gender", "女性");                
        set("long", "小青青[2;37;0m
它是帝沫沫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "aiw");
        set("owner_name", "帝沫沫");
        set_temp("owner", "aiw");
        set_temp("owner_name", "帝沫沫");
        ::setup();
}
