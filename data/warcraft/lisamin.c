// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小貓[2;37;0m[2;37;0m", ({"nio"}));        
        set("gender", "男性");                
        set("long", "小貓[2;37;0m
它是慕容響亮的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lisamin");
        set("owner_name", "慕容響亮");
        set_temp("owner", "lisamin");
        set_temp("owner_name", "慕容響亮");
        ::setup();
}
