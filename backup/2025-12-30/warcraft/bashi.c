// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("公交車[2;37;0m[2;37;0m", ({"bus"}));        
        set("gender", "男性");                
        set("long", "新型環保公交車，主動投幣，不找零錢，謝謝合作。[2;37;0m
它是巴士司機的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "bashi");
        set("owner_name", "巴士司機");
        set_temp("owner", "bashi");
        set_temp("owner_name", "巴士司機");
        ::setup();
}
