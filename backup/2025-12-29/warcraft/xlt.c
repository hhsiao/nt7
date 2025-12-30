// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蒼井空[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "女性");                
        set("long", "蒼井空[2;37;0m
它是洩立停的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xlt");
        set("owner_name", "洩立停");
        set_temp("owner", "xlt");
        set_temp("owner_name", "洩立停");
        ::setup();
}
