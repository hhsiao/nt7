// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m白[31m龍[1;37m上[34m天[2;37;0m[2;37;0m", ({"azi"}));        
        set("gender", "女性");                
        set("long", "天的見證[2;37;0m
它是狂徒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xxa");
        set("owner_name", "狂徒");
        set_temp("owner", "xxa");
        set_temp("owner_name", "狂徒");
        ::setup();
}
