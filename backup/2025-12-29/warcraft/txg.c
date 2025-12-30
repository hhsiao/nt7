// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大鳥[2;37;0m[2;37;0m", ({"quer"}));        
        set("gender", "女性");                
        set("long", "大[2;37;0m
它是鈦炫的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "txg");
        set("owner_name", "鈦炫");
        set_temp("owner", "txg");
        set_temp("owner_name", "鈦炫");
        ::setup();
}
