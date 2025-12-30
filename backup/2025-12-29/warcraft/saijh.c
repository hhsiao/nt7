// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m金花[2;37;0m[2;37;0m", ({"saijhs"}));        
        set("gender", "女性");                
        set("long", "哈哈[2;37;0m
它是賽金花的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "saijh");
        set("owner_name", "賽金花");
        set_temp("owner", "saijh");
        set_temp("owner_name", "賽金花");
        ::setup();
}
