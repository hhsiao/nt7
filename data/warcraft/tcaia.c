// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("六缸哈雷[2;37;0m[2;37;0m", ({"halei"}));        
        set("gender", "女性");                
        set("long", "六缸哈雷[2;37;0m
它是納尼好運的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tcaia");
        set("owner_name", "納尼好運");
        set_temp("owner", "tcaia");
        set_temp("owner_name", "納尼好運");
        ::setup();
}
