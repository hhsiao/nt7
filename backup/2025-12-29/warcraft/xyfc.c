// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蒼龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "女性");                
        set("long", "蒼龍[2;37;0m
它是軒轅茗月的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xyfc");
        set("owner_name", "軒轅茗月");
        set_temp("owner", "xyfc");
        set_temp("owner_name", "軒轅茗月");
        ::setup();
}
