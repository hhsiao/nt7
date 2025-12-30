// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m如意虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "魔幻如意老虎[2;37;0m
它是楚嘯風的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wyrxlm");
        set("owner_name", "楚嘯風");
        set_temp("owner", "wyrxlm");
        set_temp("owner_name", "楚嘯風");
        ::setup();
}
