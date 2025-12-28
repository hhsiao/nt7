// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m奧妮克希亞[2;37;0m[2;37;0m", ({"jyi"}));        
        set("gender", "女性");                
        set("long", "奧妮克希亞[2;37;0m
它是劍一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jianyi");
        set("owner_name", "劍一");
        set_temp("owner", "jianyi");
        set_temp("owner_name", "劍一");
        ::setup();
}
