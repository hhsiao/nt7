// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "朱雀[2;37;0m
它是星宿一號的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ntxxa");
        set("owner_name", "星宿一號");
        set_temp("owner", "ntxxa");
        set_temp("owner_name", "星宿一號");
        ::setup();
}
