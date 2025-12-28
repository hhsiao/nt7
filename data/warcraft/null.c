// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m萬年陸龜[2;37;0m[2;37;0m", ({"turtle"}));        
        set("gender", "男性");                
        set("long", "這是一隻萬年陸龜，打它不漲經驗。[2;37;0m
它是慕容逵的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "null");
        set("owner_name", "慕容逵");
        set_temp("owner", "null");
        set_temp("owner_name", "慕容逵");
        ::setup();
}
