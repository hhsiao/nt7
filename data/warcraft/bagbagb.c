// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"alias_m_whistle_zixc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是赫連小魚的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "bagbagb");
        set("owner_name", "赫連小魚");
        set_temp("owner", "bagbagb");
        set_temp("owner_name", "赫連小魚");
        ::setup();
}
