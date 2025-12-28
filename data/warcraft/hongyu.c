// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m五靈王[2;37;0m[2;37;0m", ({"wulinwang"}));        
        set("gender", "女性");                
        set("long", "豬豬俠變身戰隊[2;37;0m
它是宏宇的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hongyu");
        set("owner_name", "宏宇");
        set_temp("owner", "hongyu");
        set_temp("owner_name", "宏宇");
        ::setup();
}
