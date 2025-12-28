// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m世京[2;37;0m[2;37;0m", ({"wuminghero"}));        
        set("gender", "男性");                
        set("long", "$BLINK$$HIW$世京[2;37;0m
它是無命的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wuming");
        set("owner_name", "無命");
        set_temp("owner", "wuming");
        set_temp("owner_name", "無命");
        ::setup();
}
