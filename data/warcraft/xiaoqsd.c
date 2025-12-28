// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m小紅[2;37;0m[2;37;0m", ({"sleep_bag"}));        
        set("gender", "女性");                
        set("long", "我的乖乖紅[2;37;0m
它是墨甜的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xiaoqsd");
        set("owner_name", "墨甜");
        set_temp("owner", "xiaoqsd");
        set_temp("owner_name", "墨甜");
        ::setup();
}
