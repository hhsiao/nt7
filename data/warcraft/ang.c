// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白鳥[2;37;0m[2;37;0m", ({"bniao"}));        
        set("gender", "男性");                
        set("long", "白鳥[2;37;0m
它是丹師蛾的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ang");
        set("owner_name", "丹師蛾");
        set_temp("owner", "ang");
        set_temp("owner_name", "丹師蛾");
        ::setup();
}
