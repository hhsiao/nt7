// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m烏雲[5m[1;37m閃電駒[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹西域神駒通體雪白，追風逐電、龍行虎步，神駿非常。[2;37;0m
它是方世玉的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "shiyu");
        set("owner_name", "方世玉");
        set_temp("owner", "shiyu");
        set_temp("owner_name", "方世玉");
        ::setup();
}
