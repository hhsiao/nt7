// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m墨麒麟[2;37;0m[2;37;0m", ({"whitehorse"}));        
        set("gender", "男性");                
        set("long", "長得像馬的一頭麒麟。[2;37;0m
它是唐三藏的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tangsz");
        set("owner_name", "唐三藏");
        set_temp("owner", "tangsz");
        set_temp("owner_name", "唐三藏");
        ::setup();
}
