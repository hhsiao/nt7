// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("資依依[2;37;0m[2;37;0m", ({"ziziaaa"}));        
        set("gender", "女性");                
        set("long", "自由的飛翔[2;37;0m
它是姿啊的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zizia");
        set("owner_name", "姿啊");
        set_temp("owner", "zizia");
        set_temp("owner_name", "姿啊");
        ::setup();
}
