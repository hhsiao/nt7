// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哈哈哈[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "do l,hp[2;37;0m
它是玩單的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "alp");
        set("owner_name", "玩單");
        set_temp("owner", "alp");
        set_temp("owner_name", "玩單");
        ::setup();
}
