// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍[2;37;0m[2;37;0m", ({"xiaolong"}));        
        set("gender", "男性");                
        set("long", "龍小龍[2;37;0m
它是小菜的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ymer");
        set("owner_name", "小菜");
        set_temp("owner", "ymer");
        set_temp("owner_name", "小菜");
        ::setup();
}
