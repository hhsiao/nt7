// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m大白虎[2;37;0m[2;37;0m", ({"wtiger"}));        
        set("gender", "女性");                
        set("long", "這是長隆野生動物園的變異大白虎[2;37;0m
它是毒小寶的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "kimid");
        set("owner_name", "毒小寶");
        set_temp("owner", "kimid");
        set_temp("owner_name", "毒小寶");
        ::setup();
}
