// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m阿布[2;37;0m[2;37;0m", ({"abu"}));        
        set("gender", "男性");                
        set("long", "阿布是一頭上古傳說中的神龍。[2;37;0m
它是慕容復燕的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jiuyong");
        set("owner_name", "慕容復燕");
        set_temp("owner", "jiuyong");
        set_temp("owner_name", "慕容復燕");
        ::setup();
}
