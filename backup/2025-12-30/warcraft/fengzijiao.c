// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大龍[2;37;0m[2;37;0m", ({"dalong"}));        
        set("gender", "女性");                
        set("long", "大龍[2;37;0m
它是慕容飛機的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fengzijiao");
        set("owner_name", "慕容飛機");
        set_temp("owner", "fengzijiao");
        set_temp("owner_name", "慕容飛機");
        ::setup();
}
