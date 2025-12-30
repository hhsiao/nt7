// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("逗戰剩佛[2;37;0m[2;37;0m", ({"cctv"}));        
        set("gender", "男性");                
        set("long", "星海雲雨的一隻幻獸而已。[2;37;0m
它是星海雲雨的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "asmmah");
        set("owner_name", "星海雲雨");
        set_temp("owner", "asmmah");
        set_temp("owner_name", "星海雲雨");
        ::setup();
}
