// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[35m工作[2;37;0m[2;37;0m", ({"workhood"}));        
        set("gender", "女性");                
        set("long", "$BLINK$$MAG$工作[2;37;0m
它是王麗的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wangli");
        set("owner_name", "王麗");
        set_temp("owner", "wangli");
        set_temp("owner_name", "王麗");
        ::setup();
}
