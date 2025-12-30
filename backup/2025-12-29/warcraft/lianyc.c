// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白虎[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是煉藥叄的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lianyc");
        set("owner_name", "煉藥叄");
        set_temp("owner", "lianyc");
        set_temp("owner_name", "煉藥叄");
        ::setup();
}
