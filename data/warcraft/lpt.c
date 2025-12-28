// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m輸出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是賴皮投機的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lpt");
        set("owner_name", "賴皮投機");
        set_temp("owner", "lpt");
        set_temp("owner_name", "賴皮投機");
        ::setup();
}
