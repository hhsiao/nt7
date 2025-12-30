// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鐺[2;37;0m[2;37;0m", ({"dang"}));        
        set("gender", "女性");                
        set("long", "鐺[2;37;0m
它是冷淒寒的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qihan");
        set("owner_name", "冷淒寒");
        set_temp("owner", "qihan");
        set_temp("owner_name", "冷淒寒");
        ::setup();
}
