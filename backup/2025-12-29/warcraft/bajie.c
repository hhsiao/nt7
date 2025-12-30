// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大花豬[2;37;0m[2;37;0m", ({"bajiebb"}));        
        set("gender", "女性");                
        set("long", "大花豬[2;37;0m
它是八戒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bajie");
        set("owner_name", "八戒");
        set_temp("owner", "bajie");
        set_temp("owner_name", "八戒");
        ::setup();
}
