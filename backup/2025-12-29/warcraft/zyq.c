// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m紅塵一步終[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "一步了卻紅塵願。[2;37;0m
它是劍宗的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "zyq");
        set("owner_name", "劍宗");
        set_temp("owner", "zyq");
        set_temp("owner_name", "劍宗");
        ::setup();
}
