// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是極度誘惑的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ricci");
        set("owner_name", "極度誘惑");
        set_temp("owner", "ricci");
        set_temp("owner_name", "極度誘惑");
        ::setup();
}
