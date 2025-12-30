// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老馬[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老馬[2;37;0m
它是悲歡自飲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qianms");
        set("owner_name", "悲歡自飲");
        set_temp("owner", "qianms");
        set_temp("owner_name", "悲歡自飲");
        ::setup();
}
