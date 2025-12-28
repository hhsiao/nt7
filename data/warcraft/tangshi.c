// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m唐柔[2;37;0m[2;37;0m[2;37;0m", ({"tangshiq"}));        
        set("gender", "女性");                
        set("long", "好看好厲害的坐騎[2;37;0m
它是唐詩的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tangshi");
        set("owner_name", "唐詩");
        set_temp("owner", "tangshi");
        set_temp("owner_name", "唐詩");
        ::setup();
}
