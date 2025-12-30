// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m神都龍王[2;37;0m[2;37;0m", ({"shen"}));        
        set("gender", "女性");                
        set("long", "這就是傳說中的神龍[2;37;0m
它是楚天行的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "line");
        set("owner_name", "楚天行");
        set_temp("owner", "line");
        set_temp("owner_name", "楚天行");
        ::setup();
}
