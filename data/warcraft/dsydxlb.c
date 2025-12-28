// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玄武[2;37;0m[2;37;0m", ({"dsy"}));        
        set("gender", "女性");                
        set("long", "這是一隻玄武[2;37;0m
它是數支的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "dsydxlb");
        set("owner_name", "數支");
        set_temp("owner", "dsydxlb");
        set_temp("owner_name", "數支");
        ::setup();
}
