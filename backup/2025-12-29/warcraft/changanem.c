// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "高貴[2;37;0m
它是長心的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "changanem");
        set("owner_name", "長心");
        set_temp("owner", "changanem");
        set_temp("owner_name", "長心");
        ::setup();
}
