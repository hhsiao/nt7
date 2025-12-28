// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小夥子[2;37;0m[2;37;0m", ({"mjid"}));        
        set("gender", "女性");                
        set("long", "小夥子[2;37;0m
它是拓鋒的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "solmj");
        set("owner_name", "拓鋒");
        set_temp("owner", "solmj");
        set_temp("owner_name", "拓鋒");
        ::setup();
}
