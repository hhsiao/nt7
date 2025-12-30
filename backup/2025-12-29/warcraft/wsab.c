// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("笨鳥[2;37;0m[2;37;0m", ({"eat_liang"}));        
        set("gender", "男性");                
        set("long", "@@@@[2;37;0m
它是小豬班班的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wsab");
        set("owner_name", "小豬班班");
        set_temp("owner", "wsab");
        set_temp("owner_name", "小豬班班");
        ::setup();
}
