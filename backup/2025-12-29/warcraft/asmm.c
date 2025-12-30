// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("火鳥[2;37;0m[2;37;0m", ({"turkey"}));        
        set("gender", "女性");                
        set("long", "hit chelonian[2;37;0m
它是決明子的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "asmm");
        set("owner_name", "決明子");
        set_temp("owner", "asmm");
        set_temp("owner_name", "決明子");
        ::setup();
}
