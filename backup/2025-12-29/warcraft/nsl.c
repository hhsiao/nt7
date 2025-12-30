// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "一隻朱雀[2;37;0m
它是蘭斯洛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "nsl");
        set("owner_name", "蘭斯洛");
        set_temp("owner", "nsl");
        set_temp("owner_name", "蘭斯洛");
        ::setup();
}
