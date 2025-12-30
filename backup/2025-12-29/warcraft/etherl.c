// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("火紅朱雀[2;37;0m[2;37;0m", ({"hhzq"}));        
        set("gender", "女性");                
        set("long", "火紅朱雀[2;37;0m
它是以太飄雪的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "etherl");
        set("owner_name", "以太飄雪");
        set_temp("owner", "etherl");
        set_temp("owner_name", "以太飄雪");
        ::setup();
}
