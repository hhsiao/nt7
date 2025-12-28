// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m仙女[2;37;0m[2;37;0m", ({"kaokao"}));        
        set("gender", "女性");                
        set("long", "風情萬種的仙女[2;37;0m
它是女特警的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "lussss");
        set("owner_name", "女特警");
        set_temp("owner", "lussss");
        set_temp("owner_name", "女特警");
        ::setup();
}
