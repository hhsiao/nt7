// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("赤兔馬[2;37;0m[2;37;0m", ({"chitu"}));        
        set("gender", "女性");                
        set("long", "這馬不好老偷懶[2;37;0m
它是紅燒肥腸的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hsfc");
        set("owner_name", "紅燒肥腸");
        set_temp("owner", "hsfc");
        set_temp("owner_name", "紅燒肥腸");
        ::setup();
}
