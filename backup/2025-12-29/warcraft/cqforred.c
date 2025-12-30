// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("張揚[2;37;0m[2;37;0m", ({"zhangyang"}));        
        set("gender", "男性");                
        set("long", "揚哥出馬 天下我有[2;37;0m
它是為紅顏的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cqforred");
        set("owner_name", "為紅顏");
        set_temp("owner", "cqforred");
        set_temp("owner_name", "為紅顏");
        ::setup();
}
