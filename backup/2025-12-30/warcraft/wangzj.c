// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("卡啦[2;37;0m[2;37;0m", ({"kala"}));        
        set("gender", "女性");                
        set("long", "沒啥個性就不描述了吧[2;37;0m
它是阿懶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wangzj");
        set("owner_name", "阿懶");
        set_temp("owner", "wangzj");
        set_temp("owner_name", "阿懶");
        ::setup();
}
