// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m魔幻獸[2;37;0m[2;37;0m", ({"tgiqo"}));        
        set("gender", "男性");                
        set("long", "$BLINK$魔幻獸[2;37;0m
它是腎虛公子的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tgihm");
        set("owner_name", "腎虛公子");
        set_temp("owner", "tgihm");
        set_temp("owner_name", "腎虛公子");
        ::setup();
}
