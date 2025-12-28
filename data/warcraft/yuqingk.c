// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "鳥類的一種。[2;37;0m
它是倉丸的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yuqingk");
        set("owner_name", "倉丸");
        set_temp("owner", "yuqingk");
        set_temp("owner_name", "倉丸");
        ::setup();
}
