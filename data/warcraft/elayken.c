// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("幻靈[2;37;0m[2;37;0m", ({"mvm"}));        
        set("gender", "女性");                
        set("long", "卓越幻靈[2;37;0m
它是澄葉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "elayken");
        set("owner_name", "澄葉");
        set_temp("owner", "elayken");
        set_temp("owner_name", "澄葉");
        ::setup();
}
