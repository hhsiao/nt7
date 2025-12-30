// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寧小二[2;37;0m[2;37;0m", ({"ningbbb"}));        
        set("gender", "女性");                
        set("long", "寧小二[2;37;0m
它是寧二的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ningb");
        set("owner_name", "寧二");
        set_temp("owner", "ningb");
        set_temp("owner_name", "寧二");
        ::setup();
}
