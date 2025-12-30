// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老黃牛[2;37;0m[2;37;0m", ({"minerride"}));        
        set("gender", "男性");                
        set("long", "長得有點猥瑣[2;37;0m
它是牛四的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "minerd");
        set("owner_name", "牛四");
        set_temp("owner", "minerd");
        set_temp("owner_name", "牛四");
        ::setup();
}
