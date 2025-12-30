// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("愛騎[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "女性");                
        set("long", "我愛我的龍龍[2;37;0m
它是趙晶的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zhaojing");
        set("owner_name", "趙晶");
        set_temp("owner", "zhaojing");
        set_temp("owner_name", "趙晶");
        ::setup();
}
