// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m藍鳳凰[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "女性");                
        set("long", "神仙狗[2;37;0m
它是鳳五毒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lfwudu");
        set("owner_name", "鳳五毒");
        set_temp("owner", "lfwudu");
        set_temp("owner_name", "鳳五毒");
        ::setup();
}
