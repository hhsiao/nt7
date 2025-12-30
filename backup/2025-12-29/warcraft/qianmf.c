// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老馬[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老馬[2;37;0m
它是舊愛新歡的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qianmf");
        set("owner_name", "舊愛新歡");
        set_temp("owner", "qianmf");
        set_temp("owner_name", "舊愛新歡");
        ::setup();
}
