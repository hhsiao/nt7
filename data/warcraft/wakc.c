// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "女性");                
        set("long", "小龍[2;37;0m
它是空虛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wakc");
        set("owner_name", "空虛");
        set_temp("owner", "wakc");
        set_temp("owner_name", "空虛");
        ::setup();
}
