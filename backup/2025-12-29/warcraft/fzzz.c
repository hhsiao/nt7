// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m傲[1;32m嬌[1;33m虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "女性");                
        set("long", "有點小傲嬌[2;37;0m
它是風中之燭的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "fzzz");
        set("owner_name", "風中之燭");
        set_temp("owner", "fzzz");
        set_temp("owner_name", "風中之燭");
        ::setup();
}
