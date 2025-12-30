// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小公雞[2;37;0m[2;37;0m", ({"gongji"}));        
        set("gender", "男性");                
        set("long", "不解釋。[2;37;0m
它是小飛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xfei");
        set("owner_name", "小飛");
        set_temp("owner", "xfei");
        set_temp("owner_name", "小飛");
        ::setup();
}
