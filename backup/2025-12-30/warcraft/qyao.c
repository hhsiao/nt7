// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("肥貓[2;37;0m[2;37;0m", ({"aoq"}));        
        set("gender", "男性");                
        set("long", "老虎[2;37;0m
它是大清藥丸的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "qyao");
        set("owner_name", "大清藥丸");
        set_temp("owner", "qyao");
        set_temp("owner_name", "大清藥丸");
        ::setup();
}
