// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("美麗強大幻獸[2;37;0m[2;37;0m", ({"zhuquezhuque"}));        
        set("gender", "女性");                
        set("long", "美麗強大幻獸[2;37;0m
它是靜五的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jinge");
        set("owner_name", "靜五");
        set_temp("owner", "jinge");
        set_temp("owner_name", "靜五");
        ::setup();
}
