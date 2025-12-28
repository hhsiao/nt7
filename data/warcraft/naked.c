// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m暗帝聖龍[2;37;0m[2;37;0m", ({"edragon"}));        
        set("gender", "男性");                
        set("long", "一條龍[2;37;0m
它是魯啦啦的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "naked");
        set("owner_name", "魯啦啦");
        set_temp("owner", "naked");
        set_temp("owner_name", "魯啦啦");
        ::setup();
}
