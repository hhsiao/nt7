// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("虎[2;37;0m[2;37;0m", ({"asd"}));        
        set("gender", "男性");                
        set("long", "虎[2;37;0m
它是劉敬的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "liujing");
        set("owner_name", "劉敬");
        set_temp("owner", "liujing");
        set_temp("owner_name", "劉敬");
        ::setup();
}
