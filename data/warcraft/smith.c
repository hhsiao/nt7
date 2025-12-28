// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m風[1;35m狼[2;37;0m[2;37;0m[2;37;0m", ({"wsmith"}));        
        set("gender", "女性");                
        set("long", "風狼[2;37;0m
它是擎雲的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "smith");
        set("owner_name", "擎雲");
        set_temp("owner", "smith");
        set_temp("owner_name", "擎雲");
        ::setup();
}
