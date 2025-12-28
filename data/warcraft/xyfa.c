// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蒼穹之青[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "女性");                
        set("long", "蒼穹之青[2;37;0m
它是常旭的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xyfa");
        set("owner_name", "常旭");
        set_temp("owner", "xyfa");
        set_temp("owner_name", "常旭");
        ::setup();
}
