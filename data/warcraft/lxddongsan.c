// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("萌虎[2;37;0m[2;37;0m", ({"menghu"}));        
        set("gender", "女性");                
        set("long", "呼呼~ [2;37;0m
它是風冰彤的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lxddongsan");
        set("owner_name", "風冰彤");
        set_temp("owner", "lxddongsan");
        set_temp("owner_name", "風冰彤");
        ::setup();
}
