// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m雞腿[2;37;0m[2;37;0m", ({"yiyayo"}));        
        set("gender", "女性");                
        set("long", "3dfads[2;37;0m
它是米大當武的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "koii");
        set("owner_name", "米大當武");
        set_temp("owner", "koii");
        set_temp("owner_name", "米大當武");
        ::setup();
}
