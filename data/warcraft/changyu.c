// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("裕張[2;37;0m[2;37;0m", ({"yuchang"}));        
        set("gender", "女性");                
        set("long", "裕張[2;37;0m
它是張裕的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "changyu");
        set("owner_name", "張裕");
        set_temp("owner", "changyu");
        set_temp("owner_name", "張裕");
        ::setup();
}
