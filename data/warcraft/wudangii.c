// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛鳥[2;37;0m[2;37;0m", ({"flybird"}));        
        set("gender", "女性");                
        set("long", "飛鳥[2;37;0m
它是武當三俠的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wudangii");
        set("owner_name", "武當三俠");
        set_temp("owner", "wudangii");
        set_temp("owner_name", "武當三俠");
        ::setup();
}
