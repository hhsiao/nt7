// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("流雲[2;37;0m[2;37;0m", ({"tofly"}));        
        set("gender", "男性");                
        set("long", "無[2;37;0m
它是謝道一的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "taoist");
        set("owner_name", "謝道一");
        set_temp("owner", "taoist");
        set_temp("owner_name", "謝道一");
        ::setup();
}
