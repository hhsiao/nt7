// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m霧[2;37;0m[1;35m影[1;33m繚[1;32m繞[2;37;0m[2;37;0m", ({"wuying"}));        
        set("gender", "男性");                
        set("long", "霧影繚繞[2;37;0m
它是霧濛濛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "foggy");
        set("owner_name", "霧濛濛");
        set_temp("owner", "foggy");
        set_temp("owner_name", "霧濛濛");
        ::setup();
}
