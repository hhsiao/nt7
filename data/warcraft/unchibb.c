// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m登[5m[1;32m龍[2;37;0m[1;37m劍[2;37;0m[2;37;0m", ({"drago"}));        
        set("gender", "女性");                
        set("long", "飛雲[2;37;0m
它是金剛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "unchibb");
        set("owner_name", "金剛");
        set_temp("owner", "unchibb");
        set_temp("owner_name", "金剛");
        ::setup();
}
