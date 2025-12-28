// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("凰兒[2;37;0m[2;37;0m", ({"aiwr"}));        
        set("gender", "女性");                
        set("long", "萌萌噠[2;37;0m
它是孫喵喵的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zmhyi");
        set("owner_name", "孫喵喵");
        set_temp("owner", "zmhyi");
        set_temp("owner_name", "孫喵喵");
        ::setup();
}
