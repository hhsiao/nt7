// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("背拖車[2;37;0m[2;37;0m", ({"tttb"}));        
        set("gender", "男性");                
        set("long", "背拖車[2;37;0m
它是背倉庫的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cangkub");
        set("owner_name", "背倉庫");
        set_temp("owner", "cangkub");
        set_temp("owner_name", "背倉庫");
        ::setup();
}
