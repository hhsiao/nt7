// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m窮奇熊[2;37;0m[2;37;0m", ({"gaze"}));        
        set("gender", "男性");                
        set("long", "桶桶熊[2;37;0m
它是酒吞的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "vanitog");
        set("owner_name", "酒吞");
        set_temp("owner", "vanitog");
        set_temp("owner_name", "酒吞");
        ::setup();
}
