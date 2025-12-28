// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老鳥[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "老鳥[2;37;0m
它是拿腰帶的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "nayao");
        set("owner_name", "拿腰帶");
        set_temp("owner", "nayao");
        set_temp("owner_name", "拿腰帶");
        ::setup();
}
