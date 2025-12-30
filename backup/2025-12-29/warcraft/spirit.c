// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m龍船[2;37;0m[2;37;0m", ({"dragons"}));        
        set("gender", "男性");                
        set("long", "一艘很漂亮的龍舟，會飛的.....[2;37;0m
它是渡心的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "spirit");
        set("owner_name", "渡心");
        set_temp("owner", "spirit");
        set_temp("owner_name", "渡心");
        ::setup();
}
