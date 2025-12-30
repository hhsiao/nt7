// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小獸[2;37;0m[2;37;0m", ({"xiaoshou"}));        
        set("gender", "男性");                
        set("long", "666[2;37;0m
它是九歌的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ninesong");
        set("owner_name", "九歌");
        set_temp("owner", "ninesong");
        set_temp("owner_name", "九歌");
        ::setup();
}
