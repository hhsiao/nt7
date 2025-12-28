// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是葉良辰的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "ylc");
        set("owner_name", "葉良辰");
        set_temp("owner", "ylc");
        set_temp("owner_name", "葉良辰");
        ::setup();
}
