// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m流雲[2;37;0m[2;37;0m", ({"que"}));        
        set("gender", "男性");                
        set("long", "這是一隻叫流雲的鳥，很普通..[2;37;0m
它是鐵血舞裳的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "canwdb");
        set("owner_name", "鐵血舞裳");
        set_temp("owner", "canwdb");
        set_temp("owner_name", "鐵血舞裳");
        ::setup();
}
