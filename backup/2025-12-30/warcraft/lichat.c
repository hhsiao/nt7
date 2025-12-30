// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("獨孤之豬[2;37;0m[2;37;0m", ({"dugugonggong"}));        
        set("gender", "男性");                
        set("long", "士大夫[2;37;0m
它是獨孤公公的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lichat");
        set("owner_name", "獨孤公公");
        set_temp("owner", "lichat");
        set_temp("owner_name", "獨孤公公");
        ::setup();
}
