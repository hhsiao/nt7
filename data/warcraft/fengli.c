// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔毯[2;37;0m[2;37;0m", ({"maotian"}));        
        set("gender", "女性");                
        set("long", "舒福的毯子[2;37;0m
它是鳳梨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fengli");
        set("owner_name", "鳳梨");
        set_temp("owner", "fengli");
        set_temp("owner_name", "鳳梨");
        ::setup();
}
