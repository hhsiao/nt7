// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m坐騎[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "$BLK$坐[2;37;0m
它是照無眠的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zwm");
        set("owner_name", "照無眠");
        set_temp("owner", "zwm");
        set_temp("owner_name", "照無眠");
        ::setup();
}
