// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小馬[2;37;0m[2;37;0m", ({"dmbbb"}));        
        set("gender", "女性");                
        set("long", "小馬[2;37;0m
它是大米寶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dmb");
        set("owner_name", "大米寶");
        set_temp("owner", "dmb");
        set_temp("owner_name", "大米寶");
        ::setup();
}
