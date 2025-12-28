// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m飛[1;32m翔[1;36m九[1;32m州[2;37;0m[2;37;0m", ({"feiyang"}));        
        set("gender", "男性");                
        set("long", "條[2;37;0m
它是無法無天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wfwt");
        set("owner_name", "無法無天");
        set_temp("owner", "wfwt");
        set_temp("owner_name", "無法無天");
        ::setup();
}
