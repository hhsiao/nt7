// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m拉土車[2;37;0m[2;37;0m", ({"ltc"}));        
        set("gender", "女性");                
        set("long", "騎驢倒插門[2;37;0m
它是胖子的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fat");
        set("owner_name", "胖子");
        set_temp("owner", "fat");
        set_temp("owner_name", "胖子");
        ::setup();
}
