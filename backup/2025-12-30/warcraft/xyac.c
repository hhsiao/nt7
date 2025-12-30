// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m閃[1;32m閃[36m紅[1;31m星[2;37;0m[2;37;0m", ({"zhangsan"}));        
        set("gender", "男性");                
        set("long", "高大[2;37;0m
它是天體會的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "xyac");
        set("owner_name", "天體會");
        set_temp("owner", "xyac");
        set_temp("owner_name", "天體會");
        ::setup();
}
