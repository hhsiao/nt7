// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("看看天[2;37;0m[2;37;0m", ({"xianzhim"}));        
        set("gender", "男性");                
        set("long", "沒有[2;37;0m
它是世界盡頭的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xianzhi");
        set("owner_name", "世界盡頭");
        set_temp("owner", "xianzhi");
        set_temp("owner_name", "世界盡頭");
        ::setup();
}
