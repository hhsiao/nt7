// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("紙飛機[2;37;0m[2;37;0m", ({"togo"}));        
        set("gender", "男性");                
        set("long", "paper airline[2;37;0m
它是獨孤雲的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "jack");
        set("owner_name", "獨孤雲");
        set_temp("owner", "jack");
        set_temp("owner_name", "獨孤雲");
        ::setup();
}
