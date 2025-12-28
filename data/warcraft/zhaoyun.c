// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m赤兔[2;37;0m[2;37;0m", ({"super"}));        
        set("gender", "男性");                
        set("long", "全身血紅，四蹄飛雪，馬中赤兔，天下無雙。[2;37;0m
它是趙雲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zhaoyun");
        set("owner_name", "趙雲");
        set_temp("owner", "zhaoyun");
        set_temp("owner_name", "趙雲");
        ::setup();
}
