// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小靈[2;37;0m[2;37;0m", ({"lok"}));        
        set("gender", "女性");                
        set("long", "五[2;37;0m
它是文林來的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lokkza");
        set("owner_name", "文林來");
        set_temp("owner", "lokkza");
        set_temp("owner_name", "文林來");
        ::setup();
}
