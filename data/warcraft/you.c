// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
         set_name("日月鏡", ({"lcnely"}));        
        set("gender", "男性");                
        set("long", "這就是一個豬頭[2;37;0m
它是遊訊的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "you");
        set("owner_name", "遊訊");
        set_temp("owner", "you");
        set_temp("owner_name", "遊訊");
        ::setup();
}
