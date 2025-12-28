// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m快樂鳥[2;37;0m[2;37;0m", ({"flyu"}));        
        set("gender", "男性");                
        set("long", "我是一隻小~小~小鳥，一直想飛飛飛得更高[2;37;0m
它是冰寒風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lxddongone");
        set("owner_name", "冰寒風");
        set_temp("owner", "lxddongone");
        set_temp("owner_name", "冰寒風");
        ::setup();
}
