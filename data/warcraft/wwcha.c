// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("荒獸[2;37;0m[2;37;0m", ({"ppp"}));        
        set("gender", "女性");                
        set("long", "荒獸[2;37;0m
它是大波龍的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wwcha");
        set("owner_name", "大波龍");
        set_temp("owner", "wwcha");
        set_temp("owner_name", "大波龍");
        ::setup();
}
