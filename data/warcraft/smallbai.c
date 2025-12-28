// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "小白的朱雀[2;37;0m
它是姜曉白的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "smallbai");
        set("owner_name", "姜曉白");
        set_temp("owner", "smallbai");
        set_temp("owner_name", "姜曉白");
        ::setup();
}
