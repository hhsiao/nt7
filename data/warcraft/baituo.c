// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白駱駝[2;37;0m[2;37;0m[2;37;0m", ({"baituoer"}));        
        set("gender", "女性");                
        set("long", "厲害的駱駝[2;37;0m
它是拜託的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "baituo");
        set("owner_name", "拜託");
        set_temp("owner", "baituo");
        set_temp("owner_name", "拜託");
        ::setup();
}
