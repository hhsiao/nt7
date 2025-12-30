// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛飛飛飛[2;37;0m[2;37;0m", ({"fly_b"}));        
        set("gender", "女性");                
        set("long", "飛飛飛飛[2;37;0m
它是丐幫號一的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wucb");
        set("owner_name", "丐幫號一");
        set_temp("owner", "wucb");
        set_temp("owner_name", "丐幫號一");
        ::setup();
}
