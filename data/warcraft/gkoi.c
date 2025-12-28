// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m葉良辰[2;37;0m[2;37;0m", ({"yiyayo"}));        
        set("gender", "女性");                
        set("long", "的發放[2;37;0m
它是華六的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gkoi");
        set("owner_name", "華六");
        set_temp("owner", "gkoi");
        set_temp("owner_name", "華六");
        ::setup();
}
