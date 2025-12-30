// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m鳳翅[1;35m天翔[2;37;0m[2;37;0m", ({"mque"}));        
        set("gender", "女性");                
        set("long", "111[2;37;0m
它是夢蝶的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mengdie");
        set("owner_name", "夢蝶");
        set_temp("owner", "mengdie");
        set_temp("owner_name", "夢蝶");
        ::setup();
}
