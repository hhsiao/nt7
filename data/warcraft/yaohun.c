// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("丹頂鶴[2;37;0m[2;37;0m", ({"hun"}));        
        set("gender", "男性");                
        set("long", "鳥[2;37;0m
它是藥丸魂的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yaohun");
        set("owner_name", "藥丸魂");
        set_temp("owner", "yaohun");
        set_temp("owner_name", "藥丸魂");
        ::setup();
}
