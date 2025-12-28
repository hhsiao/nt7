// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m門堪羅雀[2;37;0m[2;37;0m", ({"wod"}));        
        set("gender", "女性");                
        set("long", "門堪羅雀!!![2;37;0m
它是夜乏的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wodd");
        set("owner_name", "夜乏");
        set_temp("owner", "wodd");
        set_temp("owner_name", "夜乏");
        ::setup();
}
