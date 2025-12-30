// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m清清[2;37;0m[2;37;0m", ({"_chingching"}));        
        set("gender", "女性");                
        set("long", "這是一隻清清[2;37;0m
它是小清的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tckwan");
        set("owner_name", "小清");
        set_temp("owner", "tckwan");
        set_temp("owner_name", "小清");
        ::setup();
}
