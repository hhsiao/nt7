// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬寶寶[2;37;0m[2;37;0m", ({"zhu"}));        
        set("gender", "男性");                
        set("long", "一頭狂吃不飽的豬[2;37;0m
它是玄空飛羽的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "biph");
        set("owner_name", "玄空飛羽");
        set_temp("owner", "biph");
        set_temp("owner_name", "玄空飛羽");
        ::setup();
}
