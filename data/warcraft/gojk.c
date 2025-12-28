// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("會遁地的貓[2;37;0m[2;37;0m", ({"xiaotiger"}));        
        set("gender", "男性");                
        set("long", "會遁地的貓[2;37;0m
它是鬼影小子的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "gojk");
        set("owner_name", "鬼影小子");
        set_temp("owner", "gojk");
        set_temp("owner_name", "鬼影小子");
        ::setup();
}
