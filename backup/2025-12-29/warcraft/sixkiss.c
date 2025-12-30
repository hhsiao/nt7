// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("不死之凰[2;37;0m[2;37;0m", ({"skky"}));        
        set("gender", "男性");                
        set("long", "這是一隻普通的朱雀。[2;37;0m
它是虹劍的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sixkiss");
        set("owner_name", "虹劍");
        set_temp("owner", "sixkiss");
        set_temp("owner_name", "虹劍");
        ::setup();
}
