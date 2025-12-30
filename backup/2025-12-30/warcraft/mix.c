// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小雞雞[2;37;0m[2;37;0m", ({"mixx"}));        
        set("gender", "女性");                
        set("long", "切割後掉下來的雞雞[2;37;0m
它是影刃的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mix");
        set("owner_name", "影刃");
        set_temp("owner", "mix");
        set_temp("owner_name", "影刃");
        ::setup();
}
