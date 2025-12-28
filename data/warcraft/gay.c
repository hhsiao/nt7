// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m菊花[2;37;0m[2;37;0m", ({"juhua"}));        
        set("gender", "男性");                
        set("long", "攻防轉換契合點[2;37;0m
它是丐愛的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "gay");
        set("owner_name", "丐愛");
        set_temp("owner", "gay");
        set_temp("owner_name", "丐愛");
        ::setup();
}
