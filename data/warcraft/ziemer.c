// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鳳飛九天[2;37;0m[2;37;0m", ({"zzzzz"}));        
        set("gender", "女性");                
        set("long", "一隻朱雀[2;37;0m
它是風雪殘樓的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ziemer");
        set("owner_name", "風雪殘樓");
        set_temp("owner", "ziemer");
        set_temp("owner_name", "風雪殘樓");
        ::setup();
}
