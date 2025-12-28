// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小紅[2;37;0m[2;37;0m", ({"xiaohong"}));        
        set("gender", "女性");                
        set("long", "鳳凰小紅[2;37;0m
它是俠客行的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xkx");
        set("owner_name", "俠客行");
        set_temp("owner", "xkx");
        set_temp("owner_name", "俠客行");
        ::setup();
}
