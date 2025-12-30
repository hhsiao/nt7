// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[35m風[1;35m劍[1;37m蒼[31m月[2;37;0m[2;37;0m", ({"joe"}));        
        set("gender", "女性");                
        set("long", "相逢何必成相識[2;37;0m
它是滅雪的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "benben");
        set("owner_name", "滅雪");
        set_temp("owner", "benben");
        set_temp("owner_name", "滅雪");
        ::setup();
}
