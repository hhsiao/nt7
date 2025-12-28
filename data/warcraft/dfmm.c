// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m小紅[2;37;0m[2;37;0m", ({"bird"}));        
        set("gender", "男性");                
        set("long", "一隻通紅的朱雀[2;37;0m
它是東方妹妹的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dfmm");
        set("owner_name", "東方妹妹");
        set_temp("owner", "dfmm");
        set_temp("owner_name", "東方妹妹");
        ::setup();
}
