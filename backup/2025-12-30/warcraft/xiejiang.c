// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"xiee"}));        
        set("gender", "女性");                
        set("long", "朱雀[2;37;0m
它是金蟹將軍的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xiejiang");
        set("owner_name", "金蟹將軍");
        set_temp("owner", "xiejiang");
        set_temp("owner_name", "金蟹將軍");
        ::setup();
}
