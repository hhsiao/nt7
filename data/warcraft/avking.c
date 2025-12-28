// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白雲[2;37;0m[2;37;0m", ({"fuyun"}));        
        set("gender", "女性");                
        set("long", "白雲[2;37;0m
它是白衣的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "avking");
        set("owner_name", "白衣");
        set_temp("owner", "avking");
        set_temp("owner_name", "白衣");
        ::setup();
}
