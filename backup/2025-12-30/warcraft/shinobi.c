// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m毒獅[2;37;0m[2;37;0m", ({"lion"}));        
        set("gender", "男性");                
        set("long", "獅子，虎見之而伏，豹見之而瞑，熊見之而躍。[2;37;0m
它是病毒的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "shinobi");
        set("owner_name", "病毒");
        set_temp("owner", "shinobi");
        set_temp("owner_name", "病毒");
        ::setup();
}
