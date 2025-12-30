// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("胭脂虎[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "胭脂虎[2;37;0m
它是鬧翻天的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sanmd");
        set("owner_name", "鬧翻天");
        set_temp("owner", "sanmd");
        set_temp("owner_name", "鬧翻天");
        ::setup();
}
