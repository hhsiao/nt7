// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("阿呆[2;37;0m[2;37;0m", ({"xwdppb"}));        
        set("gender", "女性");                
        set("long", "阿呆[2;37;0m
它是武當師二的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wdppb");
        set("owner_name", "武當師二");
        set_temp("owner", "wdppb");
        set_temp("owner_name", "武當師二");
        ::setup();
}
