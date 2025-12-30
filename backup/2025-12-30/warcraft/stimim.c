// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火狐[2;37;0m[2;37;0m", ({"firefox"}));        
        set("gender", "男性");                
        set("long", "火狐[2;37;0m
它是風之影的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "stimim");
        set("owner_name", "風之影");
        set_temp("owner", "stimim");
        set_temp("owner_name", "風之影");
        ::setup();
}
