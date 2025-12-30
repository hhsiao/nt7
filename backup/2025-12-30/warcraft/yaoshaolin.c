// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("撒額是[2;37;0m[2;37;0m", ({"ooo"}));        
        set("gender", "男性");                
        set("long", "撒額是[2;37;0m
它是少林寺的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "yaoshaolin");
        set("owner_name", "少林寺");
        set_temp("owner", "yaoshaolin");
        set_temp("owner_name", "少林寺");
        ::setup();
}
