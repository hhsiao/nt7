// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m玄[1;34m武[2;37;0m[2;37;0m", ({"tortoise"}));        
        set("gender", "女性");                
        set("long", "大大大的烏龜。[2;37;0m
它是童養媳的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "xifuer");
        set("owner_name", "童養媳");
        set_temp("owner", "xifuer");
        set_temp("owner_name", "童養媳");
        ::setup();
}
