// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("圖圖[2;37;0m[2;37;0m", ({"ttz"}));        
        set("gender", "女性");                
        set("long", "傻不啦嘰的土鱉。[2;37;0m
它是豬哥本本的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "justbbz");
        set("owner_name", "豬哥本本");
        set_temp("owner", "justbbz");
        set_temp("owner_name", "豬哥本本");
        ::setup();
}
