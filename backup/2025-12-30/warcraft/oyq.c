// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("金翅大鵬鳥[2;37;0m[2;37;0m", ({"bird"}));        
        set("gender", "女性");                
        set("long", "金翅大鵬鳥[2;37;0m
它是歐陽情的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "oyq");
        set("owner_name", "歐陽情");
        set_temp("owner", "oyq");
        set_temp("owner_name", "歐陽情");
        ::setup();
}
