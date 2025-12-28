// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("守護[2;37;0m[2;37;0m", ({"lovesame"}));        
        set("gender", "男性");                
        set("long", "守護[2;37;0m
它是花叢中的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xiaopeig");
        set("owner_name", "花叢中");
        set_temp("owner", "xiaopeig");
        set_temp("owner_name", "花叢中");
        ::setup();
}
