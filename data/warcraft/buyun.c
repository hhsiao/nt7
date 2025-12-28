// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("避水金睛獸[2;37;0m[2;37;0m", ({"minerride"}));        
        set("gender", "男性");                
        set("long", "老黃牛[2;37;0m
它是步驚雲的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "buyun");
        set("owner_name", "步驚雲");
        set_temp("owner", "buyun");
        set_temp("owner_name", "步驚雲");
        ::setup();
}
