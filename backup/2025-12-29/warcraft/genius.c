// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m冰焰鳳凰[2;37;0m[2;37;0m", ({"phoenix"}));        
        set("gender", "女性");                
        set("long", "沐浴在寒冰火焰中的鳳凰神獸。[2;37;0m
它是雪舞聆風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "genius");
        set("owner_name", "雪舞聆風");
        set_temp("owner", "genius");
        set_temp("owner_name", "雪舞聆風");
        ::setup();
}
