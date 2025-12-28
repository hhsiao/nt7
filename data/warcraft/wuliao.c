// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m丘[1;35m比[1;31m龍[2;37;0m[2;37;0m", ({"xlong"}));        
        set("gender", "男性");                
        set("long", "龍龍[2;37;0m
它是無聊的魚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wuliao");
        set("owner_name", "無聊的魚");
        set_temp("owner", "wuliao");
        set_temp("owner_name", "無聊的魚");
        ::setup();
}
