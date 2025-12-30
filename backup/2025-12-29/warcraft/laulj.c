// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("方寶寶[2;37;0m[2;37;0m", ({"lauljbb"}));        
        set("gender", "男性");                
        set("long", "方寶寶[2;37;0m
它是不詳刀的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "laulj");
        set("owner_name", "不詳刀");
        set_temp("owner", "laulj");
        set_temp("owner_name", "不詳刀");
        ::setup();
}
