// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"yitian"}));        
        set("gender", "女性");                
        set("long", "這就是四神獸之一的朱雀。[2;37;0m
它是虛擬人的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dammy");
        set("owner_name", "虛擬人");
        set_temp("owner", "dammy");
        set_temp("owner_name", "虛擬人");
        ::setup();
}
