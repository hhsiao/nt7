// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m諸葛亮[2;37;0m[2;37;0m", ({"zgl"}));        
        set("gender", "男性");                
        set("long", "天上地下阿彌陀佛[2;37;0m
它是諸葛不亮的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zgbl");
        set("owner_name", "諸葛不亮");
        set_temp("owner", "zgbl");
        set_temp("owner_name", "諸葛不亮");
        ::setup();
}
