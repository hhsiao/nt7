// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小豬籠[2;37;0m[2;37;0m", ({"hmjaq"}));        
        set("gender", "男性");                
        set("long", "豬一隻[2;37;0m
它是當小鬼的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "hmja");
        set("owner_name", "當小鬼");
        set_temp("owner", "hmja");
        set_temp("owner_name", "當小鬼");
        ::setup();
}
