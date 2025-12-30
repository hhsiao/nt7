// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m武林列傳[2;37;0m[2;37;0m", ({"wiiz"}));        
        set("gender", "女性");                
        set("long", "武林列傳[2;37;0m
它是豬三的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wllz");
        set("owner_name", "豬三");
        set_temp("owner", "wllz");
        set_temp("owner_name", "豬三");
        ::setup();
}
