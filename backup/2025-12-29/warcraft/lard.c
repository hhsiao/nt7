// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m黃色螳螂[2;37;0m[2;37;0m", ({"lards"}));        
        set("gender", "男性");                
        set("long", "我的寵物[2;37;0m
它是數緣的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lard");
        set("owner_name", "數緣");
        set_temp("owner", "lard");
        set_temp("owner_name", "數緣");
        ::setup();
}
