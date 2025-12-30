// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("淚水[2;37;0m[2;37;0m", ({"kou"}));        
        set("gender", "女性");                
        set("long", "一滴晶瑩的淚珠從臉頰滑□過[2;37;0m
它是孤星淚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xinglei");
        set("owner_name", "孤星淚");
        set_temp("owner", "xinglei");
        set_temp("owner_name", "孤星淚");
        ::setup();
}
