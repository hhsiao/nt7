// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻騎[2;37;0m[2;37;0m", ({"mohuangqi"}));        
        set("gender", "女性");                
        set("long", "貓兒[2;37;0m
它是重溫惜夢的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ssyun");
        set("owner_name", "重溫惜夢");
        set_temp("owner", "ssyun");
        set_temp("owner_name", "重溫惜夢");
        ::setup();
}
