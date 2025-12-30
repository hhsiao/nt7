// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m棉花糖[2;37;0m[2;37;0m", ({"tigger"}));        
        set("gender", "男性");                
        set("long", "白乎乎的一團，可別被它的表面所矇蔽。戰鬥狀態可是威風凜凜滴.[2;37;0m
它是任雲飛的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "cloudy");
        set("owner_name", "任雲飛");
        set_temp("owner", "cloudy");
        set_temp("owner_name", "任雲飛");
        ::setup();
}
