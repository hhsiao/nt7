// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("丸子[2;37;0m[2;37;0m", ({"yqw"}));        
        set("gender", "女性");                
        set("long", "丸子[2;37;0m
它是司馬玉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yufqing");
        set("owner_name", "司馬玉");
        set_temp("owner", "yufqing");
        set_temp("owner_name", "司馬玉");
        ::setup();
}
