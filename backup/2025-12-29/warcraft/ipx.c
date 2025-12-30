// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m紅[1;32m綠[1;37m毛毛怪[2;37;0m[2;37;0m", ({"peach"}));        
        set("gender", "女性");                
        set("long", "一隻長了一身紅毛，頭頂一撮綠毛的怪麒麟。[2;37;0m
它是薄東來的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ipx");
        set("owner_name", "薄東來");
        set_temp("owner", "ipx");
        set_temp("owner_name", "薄東來");
        ::setup();
}
