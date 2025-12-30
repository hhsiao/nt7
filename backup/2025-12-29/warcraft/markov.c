// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("彩雲[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "翱翔高空的朱雀[2;37;0m
它是馬可夫的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "markov");
        set("owner_name", "馬可夫");
        set_temp("owner", "markov");
        set_temp("owner_name", "馬可夫");
        ::setup();
}
