// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("埃鳳[2;37;0m[2;37;0m", ({"waa"}));        
        set("gender", "女性");                
        set("long", "埃鳳[2;37;0m
它是心娃的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wawa");
        set("owner_name", "心娃");
        set_temp("owner", "wawa");
        set_temp("owner_name", "心娃");
        ::setup();
}
