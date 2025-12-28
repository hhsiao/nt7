// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("胖呀米[2;37;0m[2;37;0m", ({"yummy"}));        
        set("gender", "男性");                
        set("long", "瘋語獨有[2;37;0m
它是瘋語黑山的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "tudodo");
        set("owner_name", "瘋語黑山");
        set_temp("owner", "tudodo");
        set_temp("owner_name", "瘋語黑山");
        ::setup();
}
