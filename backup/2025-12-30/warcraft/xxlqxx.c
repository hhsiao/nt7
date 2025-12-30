// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m熱乎燒餅[2;37;0m[2;37;0m", ({"shaobing"}));        
        set("gender", "女性");                
        set("long", "熱乎燒餅[2;37;0m
它是武大星的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xxlqxx");
        set("owner_name", "武大星");
        set_temp("owner", "xxlqxx");
        set_temp("owner_name", "武大星");
        ::setup();
}
