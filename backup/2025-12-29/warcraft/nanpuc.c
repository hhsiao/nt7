// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "鳥類的一種。[2;37;0m
它是男僕的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "nanpuc");
        set("owner_name", "男僕");
        set_temp("owner", "nanpuc");
        set_temp("owner_name", "男僕");
        ::setup();
}
