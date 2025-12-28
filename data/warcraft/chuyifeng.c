// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("風雲再起[2;37;0m[2;37;0m", ({"yifeng"}));        
        set("gender", "男性");                
        set("long", "風雲再起[2;37;0m
它是楚易風的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "chuyifeng");
        set("owner_name", "楚易風");
        set_temp("owner", "chuyifeng");
        set_temp("owner_name", "楚易風");
        ::setup();
}
