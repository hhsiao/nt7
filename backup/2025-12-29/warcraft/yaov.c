// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m拉土車[33m[2;37;0m[2;37;0m", ({"yaovs"}));        
        set("gender", "女性");                
        set("long", "我的坐騎[2;37;0m
它是菜但的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yaov");
        set("owner_name", "菜但");
        set_temp("owner", "yaov");
        set_temp("owner_name", "菜但");
        ::setup();
}
