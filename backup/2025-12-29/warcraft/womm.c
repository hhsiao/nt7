// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m門堪八雀[2;37;0m[2;37;0m", ({"wom"}));        
        set("gender", "男性");                
        set("long", "門堪八雀！！！[2;37;0m
它是夜依叄的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "womm");
        set("owner_name", "夜依叄");
        set_temp("owner", "womm");
        set_temp("owner_name", "夜依叄");
        ::setup();
}
