// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m糊[1;32m塗[1;33m虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "女性");                
        set("long", "有點糊塗的小白虎[2;37;0m
它是風中追風的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "fzzf");
        set("owner_name", "風中追風");
        set_temp("owner", "fzzf");
        set_temp("owner_name", "風中追風");
        ::setup();
}
