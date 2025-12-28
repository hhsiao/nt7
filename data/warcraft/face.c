// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玉面麒麟王[2;37;0m[2;37;0m", ({"faceqilin"}));        
        set("gender", "男性");                
        set("long", "玉面麒麟王[2;37;0m
它是唐臉的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "face");
        set("owner_name", "唐臉");
        set_temp("owner", "face");
        set_temp("owner_name", "唐臉");
        ::setup();
}
