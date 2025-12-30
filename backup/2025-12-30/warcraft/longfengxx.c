// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙虎[2;37;0m[2;37;0m", ({"l_lfh"}));        
        set("gender", "女性");                
        set("long", "神仙虎[2;37;0m
它是鳳學學的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "longfengxx");
        set("owner_name", "鳳學學");
        set_temp("owner", "longfengxx");
        set_temp("owner_name", "鳳學學");
        ::setup();
}
