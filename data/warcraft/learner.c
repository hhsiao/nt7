// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"mhs"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是神劍傳說的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "learner");
        set("owner_name", "神劍傳說");
        set_temp("owner", "learner");
        set_temp("owner_name", "神劍傳說");
        ::setup();
}
