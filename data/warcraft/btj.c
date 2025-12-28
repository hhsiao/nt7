// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小泉彩[2;37;0m[2;37;0m", ({"omo"}));        
        set("gender", "女性");                
        set("long", "人見人愛的美女[2;37;0m
它是周倉伍的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "btj");
        set("owner_name", "周倉伍");
        set_temp("owner", "btj");
        set_temp("owner_name", "周倉伍");
        ::setup();
}
