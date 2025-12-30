// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火鳳凰[2;37;0m[2;37;0m", ({"redphoenix"}));        
        set("gender", "女性");                
        set("long", "上古火鳳凰[2;37;0m
它是嘻哈的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ashdami");
        set("owner_name", "嘻哈");
        set_temp("owner", "ashdami");
        set_temp("owner_name", "嘻哈");
        ::setup();
}
