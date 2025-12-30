// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小鳥啊[2;37;0m[2;37;0m", ({"wwqqaa"}));        
        set("gender", "男性");                
        set("long", "這不是一隻小鳥[2;37;0m
它是東方布敗的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dongfang");
        set("owner_name", "東方布敗");
        set_temp("owner", "dongfang");
        set_temp("owner_name", "東方布敗");
        ::setup();
}
