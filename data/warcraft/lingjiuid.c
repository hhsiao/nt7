// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("靈鷲一一一[2;37;0m[2;37;0m", ({"lingjiuaaa"}));        
        set("gender", "男性");                
        set("long", "靈鷲一一一[2;37;0m
它是靈鷲一號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lingjiuid");
        set("owner_name", "靈鷲一號");
        set_temp("owner", "lingjiuid");
        set_temp("owner_name", "靈鷲一號");
        ::setup();
}
