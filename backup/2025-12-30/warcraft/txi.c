// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大鳥[2;37;0m[2;37;0m", ({"quer"}));        
        set("gender", "女性");                
        set("long", "大[2;37;0m
它是臺軒的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "txi");
        set("owner_name", "臺軒");
        set_temp("owner", "txi");
        set_temp("owner_name", "臺軒");
        ::setup();
}
