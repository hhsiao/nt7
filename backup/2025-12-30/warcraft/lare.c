// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m銀色螳螂[2;37;0m[2;37;0m", ({"lares"}));        
        set("gender", "男性");                
        set("long", "我的寵物[2;37;0m
它是裡緣的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lare");
        set("owner_name", "裡緣");
        set_temp("owner", "lare");
        set_temp("owner_name", "裡緣");
        ::setup();
}
