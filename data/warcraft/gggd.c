// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("巧[2;37;0m[2;37;0m", ({"qiao"}));        
        set("gender", "男性");                
        set("long", "巧[2;37;0m
它是吖陸的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "gggd");
        set("owner_name", "吖陸");
        set_temp("owner", "gggd");
        set_temp("owner_name", "吖陸");
        ::setup();
}
