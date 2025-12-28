// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睿兒[2;37;0m[2;37;0m", ({"wrui"}));        
        set("gender", "女性");                
        set("long", "美女[2;37;0m
它是夢夢噠的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sunaw");
        set("owner_name", "夢夢噠");
        set_temp("owner", "sunaw");
        set_temp("owner_name", "夢夢噠");
        ::setup();
}
