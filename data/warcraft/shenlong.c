// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m龍飛鳳舞[2;37;0m[2;37;0m", ({"bailong"}));        
        set("gender", "女性");                
        set("long", "這是一頭小白龍。[2;37;0m
它是龍嘯天的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "shenlong");
        set("owner_name", "龍嘯天");
        set_temp("owner", "shenlong");
        set_temp("owner_name", "龍嘯天");
        ::setup();
}
