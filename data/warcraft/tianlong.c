// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("衝出來[2;37;0m[2;37;0m", ({"tianlongb"}));        
        set("gender", "男性");                
        set("long", "衝出來[2;37;0m
它是天戰的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "tianlong");
        set("owner_name", "天戰");
        set_temp("owner", "tianlong");
        set_temp("owner_name", "天戰");
        ::setup();
}
