// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "朱雀[2;37;0m
它是陳軒榭的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kngc");
        set("owner_name", "陳軒榭");
        set_temp("owner", "kngc");
        set_temp("owner_name", "陳軒榭");
        ::setup();
}
