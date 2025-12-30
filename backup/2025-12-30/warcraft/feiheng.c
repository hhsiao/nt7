// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("赤炎聖凰[2;37;0m[2;37;0m", ({"feihong"}));        
        set("gender", "男性");                
        set("long", "赤炎聖凰[2;37;0m
它是毛毛細雨的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "feiheng");
        set("owner_name", "毛毛細雨");
        set_temp("owner", "feiheng");
        set_temp("owner_name", "毛毛細雨");
        ::setup();
}
