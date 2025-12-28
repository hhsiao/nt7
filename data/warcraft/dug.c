// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m玉狻猊[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "這頭神獸半似麒麟，半似獅子，頭上長著鹿角，聲若霹靂。[2;37;0m
它是獨孤殘的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dug");
        set("owner_name", "獨孤殘");
        set_temp("owner", "dug");
        set_temp("owner_name", "獨孤殘");
        ::setup();
}
