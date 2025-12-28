// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m冰鳳凰[2;37;0m[2;37;0m", ({"ices"}));        
        set("gender", "女性");                
        set("long", "冰鳳凰[2;37;0m
它是冰靈心的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "icehai");
        set("owner_name", "冰靈心");
        set_temp("owner", "icehai");
        set_temp("owner_name", "冰靈心");
        ::setup();
}
