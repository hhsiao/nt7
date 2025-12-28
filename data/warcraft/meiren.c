// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鳳求凰[2;37;0m[2;37;0m", ({"fengqiuhuang"}));        
        set("gender", "女性");                
        set("long", "鳳求凰[2;37;0m
它是美人彎的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "meiren");
        set("owner_name", "美人彎");
        set_temp("owner", "meiren");
        set_temp("owner_name", "美人彎");
        ::setup();
}
