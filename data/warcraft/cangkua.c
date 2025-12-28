// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("頭拖車[2;37;0m[2;37;0m", ({"ttta"}));        
        set("gender", "男性");                
        set("long", "頭拖車[2;37;0m
它是頭倉庫的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cangkua");
        set("owner_name", "頭倉庫");
        set_temp("owner", "cangkua");
        set_temp("owner_name", "頭倉庫");
        ::setup();
}
