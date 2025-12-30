// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小寶貝[2;37;0m[2;37;0m", ({"chong"}));        
        set("gender", "女性");                
        set("long", "=。=[2;37;0m
它是寵兒的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "chonger");
        set("owner_name", "寵兒");
        set_temp("owner", "chonger");
        set_temp("owner_name", "寵兒");
        ::setup();
}
